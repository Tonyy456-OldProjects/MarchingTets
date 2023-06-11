
#include "Settings.h"
#include <cstdio>
#include "./Debug.h"
Settings::Settings() {}

Settings& Settings::getInstance() {
    static Settings instance;
    return instance;
}

inline bool exists (const std::string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}

bool Settings::Initialize()
{
#ifdef SAVE_FILE_PATH
    if(!exists(SAVE_FILE_PATH))
    {
        debug << "settings file does not exist";
        return false;
    } 
#else
    debug << "No settings file";
    return false;
#endif

    std::ifstream file(SAVE_FILE_PATH);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file: " << SAVE_FILE_PATH << std::endl;
        return false;
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
        if(STInt(value, intVal))
        {
            savedSettings[key] = intVal;
            continue;
        }

        bool boolVal;
        if(STBool(value, boolVal))
        {
            savedSettings[key] = boolVal;
            continue;
        } 

        double doubleVal;
        if(STDouble(value, doubleVal))
        {
            savedSettings[key] = doubleVal;
            continue;
        }

        float floatVal;
        if(STFloat(value, floatVal))
        {
            savedSettings[key] = floatVal;
            continue;
        }

        // Store the key-value pair in the settings dictionary
        savedSettings[key] = value;
    }

    file.close();
    return true;
}

void Settings::Print() const
{
    std::cout << "[" << std::endl;
    for (const auto& pair : savedSettings) {
        const std::string& key= pair.first;
        const boost::any& value = pair.second;
        printf(" %15s, ", key.c_str());

        try {
            // Try to cast the value to the appropriate type and print it
            if (value.type() == typeid(int)) {
                std::cout << "(int)    ";
                std::cout << boost::any_cast<int>(value);

            } else if (value.type() == typeid(double)) {
                std::cout << "(double) ";
                std::cout << boost::any_cast<double>(value);

            } else if (value.type() == typeid(std::string)) {
                std::cout << "(string) ";
                std::cout << boost::any_cast<std::string>(value);

            } else if (value.type() == typeid(bool)) {
                std::cout << "(bool)   ";
                std::cout << boost::any_cast<bool>(value);

            } else if (value.type() == typeid(float)) {
                std::cout << "(float)  ";
                std::cout << boost::any_cast<float>(value);

            } else {

                std::cout << "Unknown type";
            }
        } catch (const boost::bad_any_cast&) {
            std::cout << "Type mismatch";
        }
        std::cout << std::endl;
    }
    std::cout << "]" << std::endl;
}

template<typename T>
bool Settings::TryGetSetting(const std::string& key, T& value) const 
{
    auto it = savedSettings.find(key);
    if (it != savedSettings.end()) {
        try {
            value = boost::any_cast<T>(it->second);
            return true;
        } catch (const boost::bad_any_cast& ex) {
            std::cout << "Error: Unable to cast setting '" << key << "' to type "
                      << typeid(T).name() << std::endl;
            return false;
        }
    } else {
        std::cout << "Error: Setting '" << key << "' not found" << std::endl;
        return false;
    }
}

template<typename T>
T& Settings::GetSetting(const std::string& key, T& default_value) const 
{
    auto it = savedSettings.find(key);
    if (it != savedSettings.end()) {
        try {
            return boost::any_cast<T>(it->second);
        } catch (const boost::bad_any_cast& ex) {
            std::cout << "Error: Unable to cast setting '" << key << "' to type "
                      << typeid(T).name() << std::endl;
            return default_value;
        }
    } else {
        return default_value;
    }
}
