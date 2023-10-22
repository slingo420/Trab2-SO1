#include "fifo.hpp"

unsigned int FIFO::run(const std::vector<int>& ref_vector, unsigned long long num_frames) {
    std::queue<int> page_queue;
    std::unordered_set<int> frame_set;
    unsigned int page_faults = 0;
    
    for (int page : ref_vector) {
        if (frame_set.find(page) == frame_set.end()) {
            if (page_queue.size() == num_frames) {
                int victim = page_queue.front();
                page_queue.pop();
                frame_set.erase(victim);
            }
            page_faults++;
            frame_set.insert(page);
            page_queue.push(page);
        }
    }
    return page_faults;
}
