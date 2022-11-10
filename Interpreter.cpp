//
// Created by Alex Mercer on 11/8/22.
//

#include "Interpreter.h"

Interpreter::Interpreter() {}

void Interpreter::interpret(DatalogProgram datalogProgram) {
    this->datalogProgram = datalogProgram;
    interpretSchemes();
    interpretFacts();
    interpretQueries();

}

std::string Interpreter::toString() {
    return database.toString();
}

void Interpreter::interpretSchemes() {
    for(const Predicate& scheme : this->datalogProgram.getSchemes()) {
        Relation* newRelation = new Relation();

        Header headers;

        for(const auto & parameter : scheme.getParameters()) {
            headers.push_back(parameter.toString());
        }

        newRelation->setName(scheme.getId());
        newRelation->setHeader(headers);

        database.addRelation(newRelation);
    }
}

void Interpreter::interpretFacts() {
    for(const Predicate& fact : this->datalogProgram.getFacts()) {

        Relation* relation = database.getRelation(fact.getId());

        Tuple tuples;

        for ( const Parameter& parameter : fact.getParameters()) {
            tuples.addValue(parameter.toString());
        }
        relation->addTuples(tuples);
    }
}

void Interpreter::interpretQueries() {
    for (Predicate query : this->datalogProgram.getQueries()) {
        evaluatePredicate(query);
    }
}

Relation Interpreter::evaluatePredicate(Predicate p) {
    std::map<std::string, int> stringToIndex = std::map<std::string, int>();
    std::vector<int> projectIndex = std::vector<int>();
    std::vector<std::string> renameString = std::vector<std::string>();

    Relation relation = database.getCopy(p.getId());

    for (int i = 0; i < p.getParameters().size(); ++i) {
        std::string parameterStr = p.getParameters().at(i).toString();

        if (p.getParameters()[i].toString()[0] == '\'') {
            relation = relation.selectConst(i, parameterStr);
        } else {
            if (stringToIndex.find(parameterStr) == stringToIndex.end() ) {
                stringToIndex[parameterStr] = i;
                projectIndex.push_back(i);
                renameString.push_back(parameterStr);

            } else if (stringToIndex.find(parameterStr) != stringToIndex.end()){
                relation = relation.selectVar(i, stringToIndex.at(parameterStr));
            }
        }
    }
    relation = relation.project(projectIndex);
    relation = relation.rename(renameString);

    std::cout << p.toString() << relation.toString();

    return relation;
}
