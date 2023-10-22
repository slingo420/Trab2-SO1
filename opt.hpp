#ifndef OPT_HPP
#define OPT_HPP

#include <vector>
#include <unordered_set>
#include <list>

#include "algorithm.hpp"

class OPT : public Algorithm {
public:
    unsigned int run(const std::vector<int>& ref_vector, unsigned long long num_frames); 
};

#endif
