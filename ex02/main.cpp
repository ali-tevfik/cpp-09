#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; i++)
    {
        if(argv[i][0] < 48 || argv[i][0] > 57) {
            std::cout << "Error: bad input." << std::endl;
            return 1;
        }
        vec.push_back(std::stoi(argv[i]));
        deq.push_back(std::stoi(argv[i]));
    }
    
    for (int y = 0; y < argc - 1; y++)
    {
        std::cout << "vec " << vec[y] << std::endl;
        std::cout << "deq " << deq[y] << std::endl;
    }
    

}