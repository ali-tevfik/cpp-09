#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    (void)argc;
    if (argc != 2){
        std::cout << "Error: could not open file." << std::endl;
        return 0;
    }
    try
    {
        BitcoinExchange btc(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    return 0;
}
