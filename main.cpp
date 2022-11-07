#include "Lexer.h"
#include "Token.h"
#include "Parser/Parser.h"
#include <string>
#include <fstream>
#include <iostream>

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
        std::cout<< "Success!" << std::endl;
        std::cout << parser->toString();

    } catch (Token* token) {
        std::cout << "  Failure! " << std::endl << token->toString() << std::endl;
    }

    delete lexer;
    delete parser;

    return 0;
}