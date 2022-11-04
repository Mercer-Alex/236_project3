#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <sstream>

enum class TokenType {
    COLON,
    COLON_DASH,
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PEREN,
    RIGHT_PEREN,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    END,
    UNDEFINED
};


class Token
{
private:
    TokenType type;
    std::string description;
    int line;
public:
    Token(TokenType type, std::string description, int line);

    std::string toString();

    TokenType getType() const;

    std::string getDescription();
};

#endif // TOKEN_H

