//
// Created by Alex Mercer on 9/23/22.
//

#ifndef PROJECT1_STARTER_CODE_COMMENTBLOCKAUTOMATON_H
#define PROJECT1_STARTER_CODE_COMMENTBLOCKAUTOMATON_H

#include "Automaton.h"

class CommentBlockAutomaton : public Automaton {
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);

public:
    CommentBlockAutomaton() : Automaton(TokenType::COMMENT) {}

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_COMMENTBLOCKAUTOMATON_H
