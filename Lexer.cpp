#include "Lexer.h"
#include "Automaton/ColonAutomaton.h"
#include "Automaton/ColonDashAutomaton.h"
#include "Automaton/AddAutomaton.h"
#include "Automaton/CommaAutomaton.h"
#include "Automaton/FactsAutomaton.h"
#include "Automaton/LeftPerenAutomaton.h"
#include "Automaton/MultiplyAutomaton.h"
#include "Automaton/PeriodAutomaton.h"
#include "Automaton/QMarkAutomaton.h"
#include "Automaton/QueriesAutomaton.h"
#include "Automaton/RulesAutomoton.h"
#include "Automaton/RightPerenAutomaton.h"
#include "Automaton/SchemesAutomaton.h"
#include "Automaton/StringAutomaton.h"
#include "Automaton/IdAutomaton.h"
#include "Automaton/CommentAutomaton.h"
#include "Automaton/CommentBlockAutomaton.h"

#include <iostream>

std::string WHITESPACE = " \r\n\t\v\f";

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new LeftPerenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new QMarkAutomaton());
    automata.push_back(new RulesAutomoton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new RightPerenAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new IdAutomaton());
    automata.push_back(new CommentAutomaton());
    automata.push_back(new CommentBlockAutomaton());
}

void Lexer::Run(std::string& input) {

    int lineNumber = 1;

    while (input.size() > 0) {
        int maxRead = 0;
        Automaton* maxAutomaton = automata[0];
        if (iswspace(input[0])) {
            if (input[0] == '\n') {
                lineNumber++;
            }
            input.erase(0, 1);
            continue;
        }

        for (auto automaton : automata) {
            int inputRead = automaton->Start(input);

            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = automaton;
            }
        }
        if (maxRead > 0) {
            Token* newToken = maxAutomaton->CreateToken(input.substr(0, maxRead), lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();
            if (newToken->getType() != TokenType::COMMENT) {
                tokens.push_back(newToken);
            }
        }
        else {
            maxRead = 1;
            Token* newToken = new Token(TokenType::UNDEFINED, input.substr(0, maxRead), lineNumber);
            tokens.push_back(newToken);
        }

        input.erase(0, maxRead);
    }

    tokens.push_back(new Token(TokenType::END, "", lineNumber));
}

std::vector<Token*> Lexer::getTokens() {
    return tokens;
}