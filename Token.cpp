#include "Token.h"

Token::Token(TokenType type, std::string description, int line) {
    this->type = type;
    this->description = description;
    this->line = line;
}

TokenType Token::getType() const {
    return type;
}

std::string Token::toString() {

    std::string tokenTypeStr;

    switch (type) {
        case TokenType::COLON:
            tokenTypeStr = "COLON";
            break;
        case TokenType::COLON_DASH:
            tokenTypeStr = "COLON_DASH";
            break;
        case TokenType::COMMA:
            tokenTypeStr = "COMMA";
            break;
        case TokenType::PERIOD:
            tokenTypeStr = "PERIOD";
            break;
        case TokenType::Q_MARK:
            tokenTypeStr = "Q_MARK";
            break;
        case TokenType::LEFT_PEREN:
            tokenTypeStr = "LEFT_PAREN";
            break;
        case TokenType::RIGHT_PEREN:
            tokenTypeStr = "RIGHT_PAREN";
            break;
        case TokenType::MULTIPLY:
            tokenTypeStr = "MULTIPLY";
            break;
        case TokenType::ADD:
            tokenTypeStr = "ADD";
            break;
        case TokenType::SCHEMES:
            tokenTypeStr = "SCHEMES";
            break;
        case TokenType::FACTS:
            tokenTypeStr = "FACTS";
            break;
        case TokenType::RULES:
            tokenTypeStr = "RULES";
            break;
        case TokenType::QUERIES:
            tokenTypeStr = "QUERIES";
            break;
        case TokenType::ID:
            tokenTypeStr = "ID";
            break;
        case TokenType::STRING:
            tokenTypeStr = "STRING";
            break;
        case TokenType::COMMENT:
            tokenTypeStr = "COMMENT";
            break;
        case TokenType::END:
            tokenTypeStr = "EOF";
            break;
        case TokenType::UNDEFINED:
            tokenTypeStr = "UNDEFINED";
            break;
        default:
            break;
    }

    std::ostringstream os;
    os << "(" << tokenTypeStr << ",\"" << description << "\"," << line << ")";

    return os.str();
}

std::string Token::getDescription() {
    return description;
}

