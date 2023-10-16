#include <iostream>
#include <vector>
#include <fstream>
#include <thread>

#include "reader.hpp"
#include "fifo.hpp"
#include "lru.hpp"
#include "printer.hpp"
#include "opt.hpp"

/*
TODO: 
    - Usar threads pra rodar cada um dos algorítmos
    - Testar o OPT manualmente
*/

int main(int argc, char* argv[]) {
    
    // Otimização para aumentar a velocidade de E/S do c++
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
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

    OPT opt(num_frames);
    int page_faults_opt = opt.run(ref_vector);

    Printer printer(num_frames, num_refs);
    printer.print_refs("FIFO", page_faults_fifo);
    printer.print_refs("LRU", page_faults_lru);
    printer.print_refs("OPT", page_faults_opt);


    return 0;
}
