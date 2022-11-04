//
// Created by Alex Mercer on 10/11/22.
//

#ifndef PREDICATE_H
#define PREDICATE_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class Parameter {
private:
    std::string parameterID;

public:
    Parameter() {};
    Parameter(std:: string newP) {
        parameterID = newP;
    }
    const std::string &toString() const {
        return parameterID;
    }

    void setParameterId(const std::string &parameterId) {
        parameterID = parameterId;
    }

    const std::string &getParameterId() const {
        return parameterID;
    }
};

class Predicate {
private:
    std::string id;
    std::vector<Parameter> predicates;

public:
    Predicate() {};

    std::string toString() {

        std::ostringstream os;

        os << id << "(";

        for (unsigned int i = 0; i < predicates.size(); ++i) {
            os << predicates[i].toString();
            if (i != predicates.size() - 1) {
                os << ",";
            }
        }
        os << ")";
        return os.str();
    }

    const std::string &getId() const {
        return id;
    }

    void setId(const std::string &id) {
        Predicate::id = id;
    }

    const std::vector<Parameter> &getParameters() const {
        return predicates;
    }

    void add(Parameter parameter) {
        predicates.push_back(parameter);
    }

    void clear() {
        predicates.clear();
    }

};

#endif // PREDICATE_H
