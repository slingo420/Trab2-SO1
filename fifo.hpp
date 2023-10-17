#ifndef FIFO_HPP
#define FIFO_HPP

#include <vector>
#include <queue>
#include <unordered_set>
#include "algorithm.hpp"

class FIFO : public Algorithm {
public:
    FIFO(std::queue<int>::size_type num_frames); 

    unsigned int run(const std::vector<int>& ref_vector); 

private:
    std::queue<int>::size_type num_frames;
    std::queue<int> page_queue;
    std::unordered_set<int> frame_set;
    unsigned int page_faults;
};

#endif
