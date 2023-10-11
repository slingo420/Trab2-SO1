#ifndef FIFO_HPP
#define FIFO_HPP

#include <vector>
#include <queue>
#include <unordered_set>

class FIFO {
public:
    FIFO(std::queue<int>::size_type num_frames); 

    int run(const std::vector<int>& ref_vector); 

private:
    std::queue<int>::size_type num_frames;
    std::queue<int> page_queue;
    std::unordered_set<int> frame_set;
    int page_faults;
};

#endif
