
#include "Settings.h"

Settings::Settings() {}

void Settings::Print() const
{
    for (const auto& pair : savedSettings) {
        const std::string& key= pair.first;
        const boost::any& value = pair.second;

        std::cout << key << ", ";

        try {
            // Try to cast the value to the appropriate type and print it
            if (value.type() == typeid(int)) {
                std::cout << "(int) ";
                std::cout << boost::any_cast<int>(value);

            } else if (value.type() == typeid(double)) {
                std::cout << "(double) ";
                std::cout << boost::any_cast<double>(value);

            } else if (value.type() == typeid(std::string)) {
                std::cout << "(string) ";
                std::cout << boost::any_cast<std::string>(value);

            } else if (value.type() == typeid(bool)) {
                std::cout << "(bool) ";
                std::cout << boost::any_cast<bool>(value);

            } else if (value.type() == typeid(float)) {
                std::cout << "(float) ";
                std::cout << boost::any_cast<float>(value);

            } else {

                std::cout << "Unknown type";
            }
        } catch (const boost::bad_any_cast&) {
            std::cout << "Type mismatch";
        }

        std::cout << std::endl;
    }
}

bool stringToBool(const std::string& str)
{
    std::istringstream iss(str);
    bool result;
    iss >> std::boolalpha >> result;
    if (iss.fail()) {
        throw std::invalid_argument("Invalid boolean value: " + str);
    }
    return result;
}

bool convertToBool(const std::string& str, bool& result)
{
    try {
        result = stringToBool(str);
        return true;
    } catch (const std::invalid_argument& e) {
        return false;
    }
}

bool convertToFloat(const std::string& str, float& result)
{
    try {
        result = std::stof(str);
        return true;
    } catch (const std::invalid_argument& e) {
        return false;
    }
}

bool convertToDouble(const std::string& str, double& result)
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

bool convertToInt(const std::string& str, int& result)
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

void Settings::Initialize(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        boost::trim(line); // Remove leading/trailing whitespaces

        // Skip empty lines or lines starting with a comment character '#'
        if (line.empty() || line[0] == '#') {
            continue;
        }

        // Split the line into key and value using the '=' delimiter
        std::size_t delimiterPos = line.find('=');
        if (delimiterPos == std::string::npos) {
            std::cerr << "Invalid line format: " << line << std::endl;
            continue;
        }

        std::string key = line.substr(0, delimiterPos);
        std::string value = line.substr(delimiterPos + 1);

        int intVal;
        if(convertToInt(value, intVal))
        {
            savedSettings[key] = intVal;
            continue;
        }

        bool boolVal;
        if(convertToBool(value, boolVal))
        {
            savedSettings[key] = boolVal;
            continue;
        } 

        double doubleVal;
        if(convertToDouble(value, doubleVal))
        {
            savedSettings[key] = doubleVal;
            continue;
        }

        float floatVal;
        if(convertToFloat(value, floatVal))
        {
            savedSettings[key] = floatVal;
            continue;
        }

        // Store the key-value pair in the settings dictionary
        savedSettings[key] = value;
    }

    file.close();
}

Settings& Settings::getInstance() {
    static Settings instance;
    return instance;
}
