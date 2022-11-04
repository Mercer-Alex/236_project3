//
// Created by Alex Mercer on 9/23/22.
//

#include "CommentAutomaton.h"
#include <iostream>

void CommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S1(const std::string& input) {
    if (input[index] == '|') {
        Serr();
    }
    else if (input[index] != '\n') {
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] == '\n' ) {
        return;
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S2(const std::string& input) {
    if (input[index] != '\n') {
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] == '\n' ) {
        return;
    }
    else {
        Serr();
    }
}
