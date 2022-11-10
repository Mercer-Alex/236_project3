//
// Created by Alex Mercer on 11/3/22.
//

#ifndef INC_236_PROJECT3_HEADER_H
#define INC_236_PROJECT3_HEADER_H


#include <string>
#include <vector>


class Header {
private:
    std::vector<std::string> attributes;

public:
    const std::vector<std::string> &getAttributes() const {
        return attributes;
    }

    void push_back(const std::string newHeader) {
        attributes.push_back(newHeader);
    }
};


#endif //INC_236_PROJECT3_HEADER_H
