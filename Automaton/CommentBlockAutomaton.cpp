//
// Created by Alex Mercer on 9/23/22.
//

#include "CommentBlockAutomaton.h"

void CommentBlockAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentBlockAutomaton::S1(const std::string& input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}

void CommentBlockAutomaton::S2(const std::string& input) {
    if (index == (int)input.size() - 1) {
        type = TokenType::UNDEFINED;
    }
    else if (input[index] != '|') {
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] == '|') {
        inputRead++;
        index++;
        S3(input);
    }
}

void CommentBlockAutomaton::S3(const std::string& input) {
    if (index == (int)input.size() - 1) {
        type = TokenType::UNDEFINED;
    }
    else if (input[index] == '#') {
        inputRead++;
        index++;
    }
    else {
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;
        S2(input);
    }
}