#include "fifo.hpp"

FIFO::FIFO(int num_frames) : num_frames(num_frames), page_faults(0) {}

int FIFO::run(const std::vector<int>& references) {
    for (int page : references) {
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
