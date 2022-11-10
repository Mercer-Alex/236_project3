//
// Created by Alex Mercer on 11/3/22.
//

#ifndef INC_236_PROJECT3_DATABASE_H
#define INC_236_PROJECT3_DATABASE_H

#include <map>
#include "Relation.h"

class Database {
private:
    std::map<std::string, Relation*> relations;

public:
    void addRelation(Relation* newRel) {
        relations.insert({newRel->getName(), newRel});
    }

    Relation* getRelation(std::string relationName) {
        Relation* relation = relations.at(relationName);
        return relation;
    }

    Relation getCopy(std::string relationName) {
        return *relations.at(relationName);
    }

    std::string toString() {
        std::stringstream ss;
        for (auto &relation: relations) {
            ss << relation.second->toString();
        }
        return ss.str();
    }
};



#endif //INC_236_PROJECT3_DATABASE_H
