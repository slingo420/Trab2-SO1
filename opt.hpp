#ifndef OPT_HPP
#define OPT_HPP

#include <vector>
#include <unordered_set>
#include <list>

class OPT {
public:
    OPT(unsigned long long num_frames)
        :num_frames{num_frames} {}

    int run(const std::vector<int>& ref_vector); 

private:
    unsigned long long num_frames;
};

#endif
