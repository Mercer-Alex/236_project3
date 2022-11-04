#include "RulesAutomoton.h"

void RulesAutomoton::S0(const std::string& input) {
    if (input[index] == 'R') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void RulesAutomoton::S1(const std::string& input) {
    if (input[index] == 'u') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}

void RulesAutomoton::S2(const std::string& input) {
    if (input[index] == 'l') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}

void RulesAutomoton::S3(const std::string& input) {
    if (input[index] == 'e') {
        inputRead++;
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}

void RulesAutomoton::S4(const std::string& input) {
    if (input[index] == 's') {
        inputRead++;
    }
    else {
        Serr();
    }
}
