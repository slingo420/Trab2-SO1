#include "lru.hpp"

unsigned int LRU::run(const std::vector<int>& ref_vector, unsigned long long num_frames) {
    std::list<int> page_list;  
    std::unordered_set<int> frame_set;
    unsigned int page_faults = 0;

    for (int page : ref_vector) {
        if (frame_set.find(page) == frame_set.end()) {
            if (frame_set.size() == num_frames) {
                int victim = page_list.front();
                page_list.pop_front();
                frame_set.erase(victim);
            }
            page_faults++;
            frame_set.insert(page);
        } else {
            page_list.remove(page);
        }
        page_list.push_back(page);
    }
    return page_faults;
}
