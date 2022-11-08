//
// Created by Alex Mercer on 11/7/22.
//

#ifndef INC_236_PROJECT3_INTERPRETER_H
#define INC_236_PROJECT3_INTERPRETER_H

#include "Parser/DatalogProgram.h"
#include "Database/Database.h"

class Interpreter {
private:
    DatalogProgram datalogProgram;
    Database database;

public:
    Interpreter();

    std::string toString();

    void interpret(DatalogProgram datalogProgram);
    void interpretSchemes();
    void interpretFacts();
    void interepretQueries();
};


#endif //INC_236_PROJECT3_INTERPRETER_H
