//
// Created by Alex Mercer on 10/11/22.
//

#include <vector>
#include "Parser.h"

DatalogProgram datalogProgram;
std::vector<Token*> tokens;

Parser::Parser() {
    index = 0;
}

Parser::~Parser() {}

std::string Parser::toString() {
    return datalogProgram.toString();
}

void Parser::parse(std::vector<Token*> tokens) {
    this->tokens = tokens;
    Match(TokenType::SCHEMES);
    Match(TokenType::COLON);
    parseScheme();
    parseSchemeList();

    Match(TokenType::FACTS);
    Match(TokenType::COLON);
    parseFactList();

    Match(TokenType::RULES);
    Match(TokenType::COLON);
    parseRuleList();

    Match(TokenType::QUERIES);
    Match(TokenType::COLON);
    parseQuery();
    parseQueryList();

    Match(TokenType::END);
}

void Parser::Match(TokenType compareToken) {
    if (compareToken == tokens[index]->getType()) {
        index++;
    }
    else {
        throw tokens[index];
    }
}

void Parser::parseScheme() {
    predicate = Predicate();
    predicate.setId(tokens[index]->getDescription());
    Match(TokenType::ID);

    Match(TokenType::LEFT_PEREN);

    parameter = Parameter();
    parameter.setParameterId(tokens[index]->getDescription());
    predicate.add(parameter);
    Match(TokenType::ID);

    parseIDList();
    Match(TokenType::RIGHT_PEREN);

    datalogProgram.schemeAdd(predicate);
}

void Parser::parseSchemeList() {
    if (TokenType::ID == tokens[index]->getType()) {
        parseScheme();
        parseSchemeList();
    }
}

void Parser::parseIDList() {
    if (TokenType::COMMA == tokens[index]->getType()) {
        Match(TokenType::COMMA);

        parameter = Parameter();
        parameter.setParameterId(tokens[index]->getDescription());
        predicate.add(parameter);
        Match(TokenType::ID);

        parseIDList();
    }
}

void Parser::parseFact() {
    predicate = Predicate();
    predicate.setId(tokens[index]->getDescription());
    Match(TokenType::ID);

    Match(TokenType::LEFT_PEREN);

    parameter = Parameter();
    parameter.setParameterId(tokens[index]->getDescription());
    predicate.add(parameter);
    Match(TokenType::STRING);

    parseStringList();
    Match(TokenType::RIGHT_PEREN);
    Match(TokenType::PERIOD);

    datalogProgram.factsAdd(predicate);
    datalogProgram.getDomain();
}

void Parser::parseFactList() {
    if (TokenType::ID == tokens[index]->getType()) {
        parseFact();
        parseFactList();
    }
}

void Parser::parseStringList() {
    if (TokenType::COMMA == tokens[index]->getType()) {
        Match(TokenType::COMMA);

        parameter = Parameter();
        parameter.setParameterId(tokens[index]->getDescription());
        predicate.add(parameter);
        Match(TokenType::STRING);

        parseStringList();
    }
}

void Parser::parseRule() {
    rule = Rule();
    parseHeadPredicate();

    Match(TokenType::COLON_DASH);

    predicate = Predicate();

    parsePredicate();
    rule.add(predicate);
    predicate = Predicate();
    predicateList();

    Match(TokenType::PERIOD);

    datalogProgram.rulesAdd(rule);
}

void Parser::parseRuleList() {
    if (TokenType::ID == tokens[index]->getType()) {
        parseRule();
        parseRuleList();
    }
}

void Parser::parseQuery() {
    predicate = Predicate();
    parsePredicate();
    Match(TokenType::Q_MARK);
    datalogProgram.queriesAdd(predicate);

}

void Parser::parseQueryList() {
    if (TokenType::ID == tokens[index]->getType()) {
        parseQuery();
        parseQueryList();
    }
}

void Parser::parameterList() {
    if (TokenType::COMMA == tokens[index]->getType()) {
        Match(TokenType::COMMA);
        parseParameter();
        parameterList();
    }
}

void Parser::parsePredicate() {
    predicate.setId(tokens[index]->getDescription());
    Match(TokenType::ID);

    Match(TokenType::LEFT_PEREN);
    parseParameter();
    parameterList();
    Match(TokenType::RIGHT_PEREN);
}

void Parser::predicateList() {
    if (TokenType::COMMA == tokens[index]->getType()) {
        Match(TokenType::COMMA);
        parsePredicate();
        rule.add(predicate);
        predicate = Predicate();
        predicateList();
    }
}

void Parser::parseHeadPredicate() {
    predicate = Predicate();
    predicate.setId(tokens[index]->getDescription());

    Match(TokenType::ID);
    Match(TokenType::LEFT_PEREN);

    parameter = Parameter();
    parameter.setParameterId(tokens[index]->getDescription());
    predicate.add(parameter);
    Match(TokenType::ID);

    parseIDList();

    rule.setHead(predicate);

    Match(TokenType::RIGHT_PEREN);
}

void Parser::parseParameter() {
    if (TokenType::STRING == tokens[index]->getType()) {
        parameter = Parameter();
        parameter.setParameterId(tokens[index]->getDescription());
        predicate.add(parameter);
        Match(TokenType::STRING);
    }
    else if (TokenType::ID == tokens[index]->getType()) {
        parameter = Parameter();
        parameter.setParameterId(tokens[index]->getDescription());
        predicate.add(parameter);
        Match(TokenType::ID);
    }
    else {
        parseExpression();
    }
}

void Parser::parseExpression() {
    if (TokenType::LEFT_PEREN == tokens[index]->getType()) {
        Match(TokenType::LEFT_PEREN);
        parseParameter();
        parseOperator();
        parseParameter();
        Match(TokenType::RIGHT_PEREN);
    }
}

void Parser::parseOperator() {
    if (TokenType::ADD == tokens[index]->getType()) {
        parameter = Parameter();
        parameter.setParameterId(tokens[index]->getDescription());
        predicate.add(parameter);
        Match(TokenType::ADD);
    }
    else if (TokenType::MULTIPLY == tokens[index]->getType()) {
        parameter = Parameter();
        parameter.setParameterId(tokens[index]->getDescription());
        predicate.add(parameter);
        Match(TokenType::MULTIPLY);
    }
}

const DatalogProgram &Parser::getDatalogProgram() const {
    return datalogProgram;
}





