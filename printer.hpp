#ifndef PRINTER_HPP
#define PRINTER_HPP

#include <vector>
#include <unordered_set>
#include <list>

class Printer {
public:
    Printer(int num_frames, int num_refs); 

    void FIFO(int page_faults);

    void LRU(int page_faults); 

private:
    int num_frames;
    int num_refs;
    int page_faults;
};

#endif
