//
// Created by Alex Mercer on 11/3/22.
//

#ifndef INC_236_PROJECT3_RELATION_H
#define INC_236_PROJECT3_RELATION_H

#include "Header.h"
#include "Tuple.h"
#include <set>
#include <sstream>

class Relation {
private:
    std::string name;
    Header columnNames;
    std::set<Tuple> tuples;

public:
    Relation() {}
    Relation(std::string name, Header columnNames) {
        this->columnNames = columnNames;
        this->name = name;
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string newName) {
        name = newName;
    }

    void setHeader(const Header col) {
        columnNames = col;
    }

    void addTuples(Tuple tuple) {
        tuples.insert(tuple);
    }

    std::string toString() {
        std::ostringstream os;

        if (this->tuples.empty())
        {
            os << "? No" << std::endl;
        }
        else {
            os << "? Yes(" << this->tuples.size() << ")" << std::endl;

            for (auto tuple: tuples) {
                if (tuple.getValues().size() != 0) {
                    os << "  ";
                    for (int i = 0; i < this->columnNames.getAttributes().size(); ++i) {
                        os << this->columnNames.getAttributes()[i] << "=" << tuple.getValues().at(i);
                        if (i != columnNames.getAttributes().size() - 1) {
                            os << ", ";
                        }
                    }
                    os << std::endl;
                }
            }
        }
        return os.str();
    }


    Relation selectConst(int indexCol, std::string value) {
        Relation newRel = Relation();
        newRel.name = this->name;
        newRel.columnNames = this->columnNames;

        for (Tuple t : this->tuples) {
            if (t.getValues().at(indexCol) == value) {
                newRel.addTuples(t);
            }
        }
        return newRel;
    }

    Relation selectVar(int indexColOne, int indexColTwo ) {
        Relation newRel = Relation();

        newRel.name = this->name;
        newRel.columnNames = this->columnNames;

        for (Tuple t : tuples) {
            if(t.getValues().at(indexColOne) == t.getValues().at(indexColTwo)) {
                newRel.addTuples(t);
            }
        }

        return newRel;
    }

    Relation project(std::vector<int> columnsProj) {
        Relation newRel = Relation();

        Header keepCol;
        for(auto & i : columnsProj) {
            keepCol.push_back(this->columnNames.getAttributes()[i]);
        }

        newRel.name = this->name;
        newRel.columnNames = keepCol;

        for (Tuple t : tuples) {
            Tuple temp;
            for (int i = 0; i < columnsProj.size(); ++i) {
                temp.addValue(t.getValues().at(columnsProj[i]));
            }
            newRel.addTuples(temp);
        }

        return newRel;
    }

    Relation rename(std::vector<std::string> newColName) {
        Header tempHeaders;
        Relation newRel = Relation();

        for(auto & i : newColName) {
            tempHeaders.push_back(i);
        }

        newRel.columnNames = tempHeaders;
        newRel.name = this->name;
        newRel.tuples = this->tuples;
        return newRel;
    }
};


#endif //INC_236_PROJECT3_RELATION_H
