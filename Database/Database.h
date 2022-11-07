//
// Created by Alex Mercer on 11/3/22.
//

#ifndef INC_236_PROJECT3_DATABASE_H
#define INC_236_PROJECT3_DATABASE_H

#include <map>
#include "Relation.h"

class Database {
private:
    std::map<std::string, Relation> relations;

public:
    void addRelation(Relation newRel) {
    }
    Relation* getRelation(std::string relationName) {
    }
    Relation getRelationCopy(std::string relationName) {
    }

};

}


#endif //INC_236_PROJECT3_DATABASE_H
