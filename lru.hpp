#ifndef LRU_HPP
#define LRU_HPP

#include <vector>
#include <unordered_set>
#include <list>

#include "algorithm.hpp"
class LRU : public Algorithm {
public:
    LRU(int num_frames); 

    unsigned int run(const std::vector<int>& ref_vector); 

private:
    unsigned long long num_frames;
    std::list<int> page_list;
    std::unordered_set<int> frame_set;
    unsigned int page_faults;
};

#endif
