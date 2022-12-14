#include "Lexer.h"
#include "Token.h"
#include "Interpreter.h"
#include "Parser/Parser.h"
#include <string>
#include <fstream>
#include <iostream>
#include <exception>

using namespace std;

int main(int argc, char** argv) {

    ifstream inputFile(argv[1]);
    string file;
    file.assign((istreambuf_iterator<char>(inputFile)),(istreambuf_iterator<char>()));


    Lexer* lexer = new Lexer();
    lexer->Run(file);

    std::vector<Token*> tokens = lexer->getTokens();

    Parser* parser = new Parser();
    try {
        parser->parse(tokens);

    } catch (Token* token) {
        std::cout << "  Failure! " << std::endl << token->toString() << std::endl;
    }

    Interpreter* interpreter = new Interpreter();
    interpreter->interpret(parser->getDatalogProgram());

    delete interpreter;
    delete lexer;
    delete parser;

    return 0;
}