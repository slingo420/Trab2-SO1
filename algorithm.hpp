#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include<vector>
class Algorithm {
    public:
        Algorithm() {}
        virtual ~Algorithm() {}
        virtual unsigned int run(const std::vector<int>& ref_vector, unsigned long long num_frames) = 0;
};

#endif