#ifndef OPT_HPP
#define OPT_HPP

#include <vector>
#include <unordered_set>
#include <list>

#include "algorithm.hpp"

class OPT : public Algorithm {
public:
    OPT(unsigned long long num_frames)
        :num_frames{num_frames} {}

    unsigned int run(const std::vector<int>& ref_vector); 

private:
    unsigned long long num_frames;
};

#endif
