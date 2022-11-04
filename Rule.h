//
// Created by Alex Mercer on 10/11/22.
//

#ifndef RULE_H
#define RULE_H


#include <vector>
#include "Predicate.h"

class Rule {
private:
    Predicate head;
    std::vector<Predicate> body;

public:
    const Predicate &getHead() const {
        return head;
    }

    void setHead(Predicate head) {
        Rule::head = head;
    }

    const std::vector<Predicate> &getBody() const {
        return body;
    }

    void setBody(const std::vector<Predicate> &body) {
        Rule::body = body;
    }


    void add(Predicate predicate) {
        if (predicate.getId() != "") {
            body.push_back(predicate);
        }
    }

    void clear() {
        body.clear();
    }

    std::string toString() {

        std::ostringstream os;

        os << head.toString() << " :- ";

        for (unsigned int i = 0; i < body.size(); ++i) {
            os << body[i].toString();
            if (i != body.size() - 1) {
                os << ",";
            }
        }
        return os.str();
    }
};

#endif // RULE_H
