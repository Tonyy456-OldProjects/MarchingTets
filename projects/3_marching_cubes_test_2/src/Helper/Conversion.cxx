#include "./Conversion.h"

#include <map>
#include <typeinfo>
#include <iostream>
#include <boost/any.hpp>
#include <boost/algorithm/string.hpp>
#include <fstream>

bool STBool_helper(const std::string& str)
{
    std::istringstream iss(str);
    bool result;
    iss >> std::boolalpha >> result;
    if (iss.fail()) {
        throw std::invalid_argument("Invalid boolean value: " + str);
    }
    return result;
}

bool STBool(const std::string& str, bool& result)
{
    try {
        result = STBool_helper(str);
        return true;
    } catch (const std::invalid_argument& e) {
        return false;
    }
}

bool STFloat(const std::string& str, float& result)
{
    try {
        result = std::stof(str);
        return true;
    } catch (const std::invalid_argument& e) {
        return false;
    }
}

bool STDouble(const std::string& str, double& result)
{
    if (str.find('f') != std::string::npos)
        return false;
    try {
        result = std::stod(str);
        return true;
    } catch (const std::invalid_argument& e) {
        return false;
    }
}

bool STInt(const std::string& str, int& result)
{
    if (str.find('.') != std::string::npos || str.find('f') != std::string::npos)
        return false;
    try {
        result = std::stoi(str);
        return true;
    } catch (const std::invalid_argument& e) {
        return false;
    }
}
