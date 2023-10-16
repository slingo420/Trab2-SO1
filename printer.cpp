#include "printer.hpp"
#include <iostream>

using namespace std;

Printer::Printer(int num_frames, int num_refs) {
    std::cout << num_frames << " quadros" << endl;
    std::cout << num_refs << " refs" << endl;
}

void Printer::print_refs(const std::string& name, int page_faults) {
    cout << name <<  ": " << page_faults << " PFs" << endl;
}
