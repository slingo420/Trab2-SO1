#include "reader.hpp"
#include <iostream>

Reader::Reader() {}

std::vector<int> Reader::read() {
    std::vector<int> lines;

    int line;
    while (std::cin >> line) {
        lines.push_back(line);
    }

    return lines;
}