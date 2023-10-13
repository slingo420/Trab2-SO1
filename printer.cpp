#include "printer.hpp"
#include <iostream>

using namespace std;

Printer::Printer(int num_frames, int num_refs) {
    std::cout << num_frames << " quadros" << endl;
    std::cout << num_refs << " refs" << endl;
}

void Printer::FIFO(int page_faults) {
    cout << "FIFO: " << page_faults << " PFs" << endl;
}

void Printer::LRU(int page_faults) {
    cout << "LRU: " << page_faults << " PFs" << endl;
}