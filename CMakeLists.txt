cmake_minimum_required(VERSION 3.23)
project(236_project3)

set(CMAKE_CXX_STANDARD 14)

add_executable(236_project3 main.cpp Automaton/AddAutomaton.h Automaton/AddAutomaton.cpp Automaton/Automaton.h Automaton/ColonDashAutomaton.h
        Automaton/ColonDashAutomaton.cpp Automaton/ColonAutomaton.h Automaton/ColonAutomaton.cpp Automaton/CommaAutomaton.cpp Automaton/CommaAutomaton.h
        Automaton/CommentAutomaton.cpp Automaton/CommentAutomaton.h Automaton/CommentBlockAutomaton.h Automaton/CommentBlockAutomaton.cpp Automaton/FactsAutomaton.h
        Automaton/FactsAutomaton.cpp Automaton/IdAutomaton.h Automaton/IdAutomaton.cpp Automaton/LeftPerenAutomaton.h Automaton/LeftPerenAutomaton.cpp Lexer.h Lexer.cpp
        Automaton/MultiplyAutomaton.h Automaton/MultiplyAutomaton.cpp Automaton/PeriodAutomaton.h Automaton/PeriodAutomaton.cpp Automaton/QMarkAutomaton.h
        Automaton/QMarkAutomaton.cpp Automaton/QueriesAutomaton.h Automaton/QueriesAutomaton.cpp Automaton/RightPerenAutomaton.h Automaton/RightPerenAutomaton.cpp
        Automaton/RulesAutomoton.h Automaton/RulesAutomoton.cpp Automaton/SchemesAutomaton.h Automaton/SchemesAutomaton.cpp Automaton/StringAutomaton.h
        Automaton/StringAutomaton.cpp Token.h Token.cpp Parser/Parser.cpp Parser/Parser.h Parser/DatalogProgram.h Parser/Predicate.h Parser/Rule.h Database/Database.h Database/Relation.h Database/Header.h Database/Tuple.h Interpreter.h Interpreter.cpp)
