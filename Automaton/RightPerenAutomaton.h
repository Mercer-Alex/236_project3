#ifndef PROJECT1_STARTER_CODE_RIGHTPERENAUTOMATON_H
#define PROJECT1_STARTER_CODE_RIGHTPERENAUTOMATON_H

#include "Automaton.h"

class RightPerenAutomaton : public Automaton
{
public:
    RightPerenAutomaton() : Automaton(TokenType::RIGHT_PEREN) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_RIGHTPERENAUTOMATON_H
