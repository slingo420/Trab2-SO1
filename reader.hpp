#ifndef READER_HPP
#define READER_HPP

#include <string>
#include <vector>

class Reader {
public:
    Reader(const std::string& filename);

    std::vector<std::string> read();

private:
    std::string filename_;
};

#endif