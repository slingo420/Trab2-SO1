#include <iostream>
#include <vector>
#include <fstream>
#include <thread>
#include <future>

#include "reader.hpp"
#include "fifo.hpp"
#include "lru.hpp"
#include "printer.hpp"
#include "opt.hpp"



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

    int num_threads = std::thread::hardware_concurrency();

    
    FIFO fifo(num_frames);
    LRU lru(num_frames);
    OPT opt(num_frames);
    auto run_algorithm = [&ref_vector, &num_frames](Algorithm *alg) {
        return alg->run(ref_vector);
    };
    
    unsigned int page_faults_fifo, page_faults_lru, page_faults_opt;
    if (num_threads <= 1) {
        page_faults_fifo = fifo.run(ref_vector);
        page_faults_lru = lru.run(ref_vector);
        page_faults_opt = opt.run(ref_vector);
    } else if (num_threads == 2) {
        auto future_opt = std::async(std::launch::async, run_algorithm, &opt);
        auto future_lru = std::async(std::launch::async, run_algorithm, &lru);

        page_faults_opt = future_opt.get();
        page_faults_lru = future_lru.get();
        page_faults_fifo = run_algorithm(&fifo);
    } else {
        auto future_fifo = std::async(std::launch::async, run_algorithm, &fifo);
        auto future_opt = std::async(std::launch::async, run_algorithm, &opt);
        auto future_lru = std::async(std::launch::async, run_algorithm, &lru);

        page_faults_opt = future_opt.get();
        page_faults_lru = future_lru.get();
        page_faults_fifo = future_fifo.get();
    }

    Printer printer(num_frames, num_refs);
    printer.print_refs("FIFO", page_faults_fifo);
    printer.print_refs("LRU", page_faults_lru);
    printer.print_refs("OPT", page_faults_opt);


    return 0;
}
