#include <iostream>
#include <vector>
#include <fstream>

#include "reader.hpp"
#include "fifo.hpp"
#include "lru.hpp"
#include "printer.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <num_quadros> <arquivo_referencias.txt>\n" << std::endl;
        return 1;
    }

    int num_frames = std::stoi(argv[1]);

    Reader reader;
    std::vector<int> ref_vector = reader.read();
    int num_refs = reader.count_refs();

    FIFO fifo(num_frames);
    int page_faults_fifo = fifo.run(ref_vector);

    LRU lru(num_frames);
    int page_faults_lru = fifo.run(ref_vector);

    Printer printer(num_frames, num_refs);
    printer.FIFO(page_faults_fifo);
    printer.LRU(page_faults_lru);

    return 0;
}
