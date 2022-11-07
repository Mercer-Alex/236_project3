//
// Created by Alex Mercer on 11/3/22.
//

#ifndef INC_236_PROJECT3_TUPLE_H
#define INC_236_PROJECT3_TUPLE_H


#include <string>
#include <vector>

class Tuple {
private:
    std::vector<std::string> values;

public:
    Tuple() {};

    bool operator< (const Tuple &rhs) const {
        return values < rhs.values;
    }

    const std::vector<std::string> &getValues() const {
        return values;
    }

    void setValues(const std::vector<std::string> &values) {
        Tuple::values = values;
    }

    std::string toString() {
        return "(" + values[0] + ", " + values[1] + ")";
    }
};


#endif //INC_236_PROJECT3_TUPLE_H
