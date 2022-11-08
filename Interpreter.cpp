//
// Created by Alex Mercer on 11/8/22.
//

#include "Interpreter.h"

Interpreter::Interpreter() {}

void Interpreter::interpret(DatalogProgram datalogProgram) {
    this->datalogProgram = datalogProgram;
    interpretSchemes();
    interpretFacts();

    std::cout << toString();
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
