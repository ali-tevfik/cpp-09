#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <float.h>



class BitcoinExchange
{
private:
    float _total;
    std::string firstDay;
    std::string lastDay;
public:
    BitcoinExchange(std::string fileName);
    ~BitcoinExchange(); 

    std::map<std::string, double> _data;
    void readData();
    // void findRate(std::string date, std::string value);
    bool isValidDate(const std::string& date_str);

    //getter setter
    float getTotal(){return _total;};
    void setTotal(float total){_total = total;};
};



#endif