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

        for(auto tuple : tuples) {
            os << name << std::endl << tuple.toString() << std::endl;
        }
        return os.str();
    }

    Relation select(int indexCol, std::string value);

    Relation select(int indexColOne, int indexColTwo );

    Relation project(std::vector<int> columnsProj);

    Relation rename(std::vector<std::string> newColName);

};


#endif //INC_236_PROJECT3_RELATION_H
