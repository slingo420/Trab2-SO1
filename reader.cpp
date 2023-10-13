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

int Reader::count_refs() {
    int references = 0;

    std::cin.clear();
    std::cin.seekg(0, std::ios::beg);

    int line;
    while (std::cin >> line) {
        references++;
    }

    return references;
}
