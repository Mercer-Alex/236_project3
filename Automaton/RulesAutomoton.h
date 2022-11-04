#ifndef PROJECT1_STARTER_CODE_RULESAUTOMOTON_H
#define PROJECT1_STARTER_CODE_RULESAUTOMOTON_H

#include "Automaton.h"

class RulesAutomoton : public Automaton {
private:
    void S4(const std::string& input);
    void S3(const std::string& input);
    void S2(const std::string& input);
    void S1(const std::string& input);
public:
    RulesAutomoton() : Automaton(TokenType::RULES) {}

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_RULESAUTOMOTON_H
