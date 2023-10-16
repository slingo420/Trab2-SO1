#ifndef LRU_HPP
#define LRU_HPP

#include <vector>
#include <unordered_set>
#include <list>

class LRU {
public:
    LRU(int num_frames); 

    int run(const std::vector<int>& ref_vector); 

private:
    unsigned long long num_frames;
    std::list<int> page_list;
    std::unordered_set<int> frame_set;
    int page_faults;
};

#endif
