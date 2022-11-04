#ifndef PROJECT1_STARTER_CODE_LEFTPERENAUTOMATON_H
#define PROJECT1_STARTER_CODE_LEFTPERENAUTOMATON_H

#include "Automaton.h"

class LeftPerenAutomaton : public Automaton
{
public:
    LeftPerenAutomaton() : Automaton(TokenType::LEFT_PEREN) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_LEFTPERENAUTOMATON_H
