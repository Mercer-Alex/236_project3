#ifndef PROJECT1_STARTER_CODE_QUERIESAUTOMATON_H
#define PROJECT1_STARTER_CODE_QUERIESAUTOMATON_H

#include "Automaton.h"

class QueriesAutomaton : public Automaton {
private:
    void S6(const std::string& input);
    void S5(const std::string& input);
    void S4(const std::string& input);
    void S3(const std::string& input);
    void S2(const std::string& input);
    void S1(const std::string& input);
public:
    QueriesAutomaton() : Automaton(TokenType::QUERIES) {}

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_QUERIESAUTOMATON_H
