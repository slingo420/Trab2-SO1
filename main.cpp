#include <iostream>
#include <vector>
#include <fstream>

#include "reader.hpp"
#include "fifo.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <num_quadros> <arquivo_referencias.txt>\n" << std::endl;
        return 1;
    }

    int num_quadros = std::stoi(argv[1]);

    Reader reader;
    std::vector<std::string> ref_vector = reader.read();

    std::cout << num_quadros << std::endl;
    for (const std::string& referencia : ref_vector) {
        std::cout << referencia << std::endl;
    }

    FIFO fifo(num_quadros);
    int page_faults = fifo.run(ref_vector);

    return 0;
}
