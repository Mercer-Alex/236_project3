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

    void addValue(std::string value) {
        values.push_back(value);
    }

    std::string toString() {
        std::ostringstream os;

        for (auto val : values) {
            os << val;
        }
        return os.str();
    }
};


#endif //INC_236_PROJECT3_TUPLE_H
