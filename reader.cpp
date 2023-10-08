#include "reader.hpp"
#include <iostream>

Reader::Reader(const std::string&) {

}

std::vector<std::string> Reader::read() {
    std::vector<std::string> lines;

    std::string line;
    while (getline(std::cin, line)) {
        lines.push_back(line);
    }

    return lines;
}
