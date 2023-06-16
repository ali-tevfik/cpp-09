#include "BitcoinExchange.hpp"

void BitcoinExchange::readData() {
	
	std::ifstream file("data.csv");
    std::string line;
    int i = 0;
    // Skip first line
    std::getline(file, line);
    // Read data from file and insert into map
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, rate;
        std::getline(ss, date, ',');
        std::getline(ss, rate, '\n');
        if (i == 0)
            firstDay = date;
        i++;
        _data[date] = std::stod(rate);
        lastDay = date;
    }
    
    std::cout << "firs day " << firstDay << std::endl;
    std::cout << "last day " << lastDay << std::endl;
}


bool BitcoinExchange::isValidDate(const std::string& date_str) {
    // Create a stringstream from the input string
    std::istringstream iss(date_str);
    
    // Extract year, month, and day from the stringstream
    int year, month, day;
    char dash1, dash2;
    iss >> year >> dash1 >> month >> dash2 >> day;
    
    // Check if input string was correctly formatted
    if (iss.fail() || dash1 != '-' || dash2 != '-') {
        return false;
    }
    
    // Check if month is in valid range
    if (month < 1 || month > 12) {
        return false;
    }
    
    // Check if day is in valid range, taking into account leap years
    bool leap_year = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
    int max_day = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        max_day = 30;
    } else if (month == 2) {
        max_day = leap_year ? 29 : 28;
    }
    if (day < 1 || day > max_day) {
        return false;
    }


 //is it before first day?
    std::istringstream firstIss(firstDay);
    
    // Extract year, month, and day from the stringstream
    int firstYear, firstMonth, firstDay;
    char firstDash1, firstDash2;
    firstIss >> firstYear >> firstDash1 >> firstMonth >> firstDash2 >> firstDay;

    //FD means First Date
    //ND means Now Date
    //LD means Last day

    if ( firstYear > year ) // FD=>2009 ND => 2011
        return false;
    else if(firstYear == year && month < firstMonth) //FD 2009-05 NY=> 2009-04
        return false;
    else if (firstYear == year && month == firstMonth && firstDay > day) //FD 2009-05-15 ND 2009-05-10
        return false;



    std::istringstream lastIss(lastDay);
    
    // Extract year, month, and day from the stringstream
    int lastYear, lastMonth, lastDay;
    char lastDash1, lastDash2;
    lastIss >> lastYear >> lastDash1 >> lastMonth >> lastDash2 >> lastDay;


    if ( lastYear < year ) // LD=>2009 ND => 2011{}
        return false;
    else if(lastYear == year && month > lastMonth) //LD 2009-05 NY=> 2009-04
        return false;
    else if (lastYear == year && month == lastMonth && lastDay < day) //LD 2009-05-15 ND 2009-05-10
        return false;

    // All checks passed, return true
    return true;
}

bool isValidValue(std::string value)
{
    double IValue;
    try
    {
        IValue = std::stof(value);
    }
    catch(const std::exception& e)
    {
        return false;
    }
    if (IValue < 0 || IValue > DBL_MAX)
        return false;
    return true;
}

BitcoinExchange::BitcoinExchange(std::string fileName)
{
    std::ifstream input_file(fileName.c_str());
    readData();
    
    std::string line;

    //check first line
    std::getline(input_file, line);
    std::istringstream iss(line);
    std::string date,value, anything;
    char seperator;
    if((iss >> date >> seperator >> value >> anything) || seperator != '|' || date.compare("date") || value.compare("value") || anything.compare(""))
    {
        std::cout << "Error: Invalid first line." << std::endl;
        return;
    }


    while (std::getline(input_file, line)) {
        std::istringstream iss(line);
        
        if(!(iss >> date >> seperator >> value) || seperator != '|')
			std::cout << "Error: bad input => " << date << std::endl;
        else if ( !isValidDate(date))
        {
           std::cout << "Error: Invalid date [" << date << "]" << std::endl;
        }
        else if(!isValidValue(value))
        {
            std::cout << "Error: not a positive number." << std::endl;
        }
        else if(std::stod(value) > 1000){
            std::cout << "Error: too large a number." << std::endl;
        }
        else {
            findRate(date);
            std::cout << date << " => " << value << " = " << getTotal() * std::stod(value) << std::endl;
        }
        
    }

    

}


std::string BitcoinExchange::oneDayBefore(std::string firstDay){
 // std::string to tm
    std::tm timeStruct = {};
    std::istringstream iss(firstDay);
    iss >> std::get_time(&timeStruct, "%Y-%m-%d");

    // convert std::tm'i std::chrono::system_clock::time_point
    std::chrono::system_clock::time_point date = std::chrono::system_clock::from_time_t(std::mktime(&timeStruct));

    // one days = 24h
    std::chrono::hours oneDay(24);

    //calculate one day before
    std::chrono::system_clock::time_point oneDayBefore = date - oneDay;

    //chrono convert tm
    std::time_t oneDayBeforeTime = std::chrono::system_clock::to_time_t(oneDayBefore);
    std::tm* oneDayBeforeTm = std::localtime(&oneDayBeforeTime);

    // date format to string
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", oneDayBeforeTm);
    std::string oneDayBeforeDateString(buffer);

    return oneDayBeforeDateString;
}

void BitcoinExchange::findRate(std::string date)
{
    std::map<std::string, double>::iterator iter = _data.find(date);
    if (iter != _data.end()) {
        setTotal(_data[date]);
    } else {
        findRate(oneDayBefore(date));
    }

}

BitcoinExchange::~BitcoinExchange()
{
}