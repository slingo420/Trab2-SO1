#ifndef FIFO_HPP
#define FIFO_HPP

#include <vector>
#include <queue>
#include <unordered_set>
#include "algorithm.hpp"

class FIFO : public Algorithm {
public:
    unsigned int run(const std::vector<int>& ref_vector, unsigned long long num_frames); 
};

#endif
