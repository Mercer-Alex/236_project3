//
// Created by Alex Mercer on 10/11/22.
//

#ifndef PARSER_H
#define PARSER_H


#include "DatalogProgram.h"
#include "../Token.h"
#include "Predicate.h"
#include "Rule.h"

class Parser {

private:
    Predicate predicate;
    Rule rule;
    Parameter parameter;

    std::vector<Token*> tokens;
    DatalogProgram datalogProgram;

    int index;

public:
    Parser();
    ~Parser();
    std::string toString();

    void Match(TokenType correctToken);

    void parseSchemeList();
    void parseScheme();
    void parseFactList();
    void parseFact();
    void parseRuleList();
    void parseRule();
    void parseQueryList();
    void parseQuery();

    void parseIDList();
    void predicateList();
    void parseStringList();

    void parameterList();
    void parseParameter();

    void parsePredicate();
    void parseHeadPredicate();

    void parseExpression();
    void parseOperator();

    void parse(std::vector<Token*> tokens);
};

#endif // PARSER_H
