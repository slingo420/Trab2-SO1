#include <iostream>
#include <vector>
#include <fstream>

#include "reader.hpp"
#include "fifo.hpp"
#include "lru.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <num_quadros> <arquivo_referencias.txt>\n" << std::endl;
        return 1;
    }

    int num_frames = std::stoi(argv[1]);
    std::cout << "Number of frames: " << num_frames << std::endl;

    std::cout << "References: " << std::endl;
    Reader reader;
    std::vector<int> ref_vector = reader.read();
    for (const int& referencia : ref_vector) {
        std::cout << referencia << std::endl;
    }

    std::cout << "FIFO" << std::endl;
    FIFO fifo(num_frames);
    int page_faults = fifo.run(ref_vector);
    std::cout << "Page faults: " << page_faults << std::endl;

    std::cout << "LRU" << std::endl;
    LRU lru(num_frames);
    page_faults = fifo.run(ref_vector);
    std::cout << "Page faults: " << page_faults << std::endl;

    return 0;
}
