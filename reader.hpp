#ifndef READER_HPP
#define READER_HPP

#include <string>
#include <vector>

class Reader {
public:
    Reader(); 

    std::vector<std::string> read();
};

#endif