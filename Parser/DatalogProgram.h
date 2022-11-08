//
// Created by Alex Mercer on 10/11/22.
//

#ifndef DATALOGPROGRAM_H
#define DATALOGPROGRAM_H

#include "Predicate.h"
#include "Rule.h"
#include <string>
#include <sstream>
#include<set>

class DatalogProgram {
private:
    std::vector<Predicate> schemes;
    std::vector<Predicate> facts;
    std::vector<Rule> rules;
    std::vector<Predicate> queries;

public:
    DatalogProgram() {}
    ~DatalogProgram() {}

    void schemeAdd(Predicate predicate) {
        schemes.push_back(predicate);
    }
    void factsAdd(Predicate predicate) {
        facts.push_back(predicate);
    }
    void rulesAdd(Rule rule) {
        rules.push_back(rule);
    }
    void queriesAdd(Predicate predicate) {
        queries.push_back(predicate);
    }

    const std::vector<Predicate> &getSchemes() const {
        return schemes;
    }

    const std::vector<Predicate> &getFacts() const {
        return facts;
    }

    const std::vector<Rule> &getRules() const {
        return rules;
    }

    const std::vector<Predicate> &getQueries() const {
        return queries;
    }

    std::set<std::string> domain;

    void getDomain() {
        for (unsigned int i = 0; i < facts.size(); ++i)
        {
            std::vector<Parameter> params = facts[i].getParameters();
            for (unsigned int j = 0; j < params.size(); ++j)
            {
                domain.insert(params[j].toString());
            }
        }
    }

    std::string toString()
    {
        std::ostringstream os;

        os << "Schemes(" << schemes.size() << "):\n";
        for (unsigned int i = 0; i < schemes.size(); ++i)
        {
            os << "  " << schemes[i].toString() << "\n";
        }

        os << "Facts(" << facts.size() << "):\n";
        for (unsigned int i = 0; i < facts.size(); ++i)
        {
            os << "  " << facts[i].toString() << ".\n";
        }

        os << "Rules(" << rules.size() << "):\n";
        for (unsigned int i = 0; i < rules.size(); ++i)
        {
            os << "  " << rules[i].toString() << ".\n";
        }

        os << "Queries(" << queries.size() << "):\n";
        for (unsigned int i = 0; i < queries.size(); ++i)
        {
            os << "  " << queries[i].toString() << "?\n";
        }

        os << "Domain(" << domain.size() << "):\n";
        for (auto itr : domain) {
            os << "  " << itr << "\n";
        }

        return os.str();
    }
};

#endif // DATALOGPROGRAM_H
