#include "opt.hpp"

#include <unordered_map>
#include <set>
#include <map>
#include <queue>
int OPT::run(const std::vector<int>& ref_vector) {
    int page_faults = 0;

    std::unordered_map<int, std::queue<int>> page_references;

    for (int i = 0; i < ref_vector.size(); ++i)
        page_references[ref_vector[i]].push(i);


    std::unordered_map<int, int> frame_map;
    std::map<int, int> frame_next_ref;
    for (int page : ref_vector) {
        auto frame = frame_map.find(page);
        if (frame_map.find(page) == frame_map.end()) {
            if (frame_map.size() == num_frames) {
                auto victim = frame_next_ref.begin();
                frame_map.erase( victim->second );
                frame_next_ref.erase(victim);
            }
            page_faults++;
        }

        int next_ref = page_references[page].front();
        frame_map[page] = next_ref;
        frame_next_ref[next_ref] = page;
    }
    return page_faults;
}
