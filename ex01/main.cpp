#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cout << "Error: Argument";
        return 1;
    }
    std::stack<int> numbers;
    std::istringstream ss(argv[1]);
    std::string token;
    while(ss >> token){
        if (token == "-" || token == "+" || token == "*" || token == "/")
        {
            if (numbers.size() < 2)
            {
                std::cout << "Errror: invalid argument" << std::endl;
                return 1;
            }
            
            int nmbr1 = numbers.top();
            numbers.pop();
            int nmbr2 = numbers.top();
            numbers.pop();

            int result;
            if(token == "-")
                result = nmbr2 - nmbr1;
            else if (token == "+")
                result = nmbr1 + nmbr2;
            else if(token == "*")
                result = nmbr1 * nmbr2;
            else
                result = nmbr2 / nmbr1; 
            numbers.push(result);
        }
        else{
            for (int i = 0; i < token[i]; i++)
            {
                if(!isdigit(token[i])){
                    std::cout << "Argument not int!" << std::endl;
                    return 1;
                }
            }
            int num = atoi(token.c_str());
            numbers.push(num);
        }
    }
    if (numbers.size() != 1){
        std::cout << "Error: invalid error" << std::endl;
        return 1;
    }
    std::cout << numbers.top() << std::endl;
    return 0;
}