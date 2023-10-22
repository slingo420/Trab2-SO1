#ifndef LRU_HPP
#define LRU_HPP

#include <vector>
#include <unordered_set>
#include <list>

#include "algorithm.hpp"
class LRU : public Algorithm {
public:
    unsigned int run(const std::vector<int>& ref_vector, unsigned long long num_frames); 
};

#endif
