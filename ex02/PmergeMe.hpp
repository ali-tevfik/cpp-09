#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

// template<typename T>
class PmergeMe {
public:
    PmergeMe(std::vector<int>& vec, std::deque<int>& deq);
    ~PmergeMe();

private:
    void deqMerge(std::deque<int>& deq, int l, int m, int r);
    void vecMerge(std::vector<int>& vec, int l, int m, int r);
    void deqSort(std::deque<int>& deq, int begin, int end);
    void vecSort(std::vector<int>& vec, int begin, int end);
};






#endif