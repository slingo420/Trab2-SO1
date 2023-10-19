#include "opt.hpp"

#include <unordered_map>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iostream>
unsigned int OPT::run(const std::vector<int>& ref_vector) {
    unsigned int page_faults = 0;

    std::unordered_map<int, std::queue<int>> page_references;

    for (unsigned long long i = 0; i < ref_vector.size(); ++i)
        page_references[ref_vector[i]].push(i);

    for (auto&[k, _] : page_references) {
        page_references[k].push(2e9 - k);
        page_references[k].pop();
    }

    std::unordered_map<int, int> frame_map;
    std::map<int, int, std::greater<int>> frame_next_ref; // queremos que a página que será lida no maior índice fique em primeirp
    for (int page : ref_vector) {
        auto frame = frame_map.find(page);
        if (frame == frame_map.end()) {
            page_faults++;
            if (frame_map.size() == num_frames) {
                auto victim = frame_next_ref.begin();

                frame_map.erase( victim->second );
                frame_next_ref.erase(victim);
            }
        }
        else {
          frame_next_ref.erase(frame->second);
        }

        int next_ref = page_references[page].front();
        page_references[page].pop();
        frame_map[page] = next_ref;
        frame_next_ref[next_ref] = page;
    }
    return page_faults;
}
