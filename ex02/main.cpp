#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; i++)
    {
        for (int x = 0; x < argv[i][x]; x++)
        {
            if(argv[i][x] < 48 || argv[i][x] > 57) {
                std::cout << "Error: bad input." << std::endl;
                return 1;
            }
        }
        
        
        vec.push_back(std::stoi(argv[i]));
        deq.push_back(std::stoi(argv[i]));
    }
    
    PmergeMe merge(vec,deq);


    

}