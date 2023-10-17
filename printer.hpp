#ifndef PRINTER_HPP
#define PRINTER_HPP

#include <vector>
#include <unordered_set>
#include <list>
#include <string>
class Printer {
public:
    Printer(int num_frames, int num_refs); 

    void print_refs(const std::string& name, unsigned int page_faults);
};

#endif
