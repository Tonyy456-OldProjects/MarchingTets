#ifndef R_SETTINGS_H
#define R_SETTINGS_H

#include <map>
#include <string>
#include <typeinfo>
#include <iostream>
#include <boost/any.hpp>
#include <boost/algorithm/string.hpp>
#include <fstream>

class Settings {
public:
    static Settings& getInstance();

    template<typename T>
    bool TryGetSetting(const std::string& key, T& value) const
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

    template <typename T>
    void SetSetting(const std::string& key, const T& value)
    {
        savedSettings[key] = value;
    }

    void Initialize(const std::string& filename);

    void Print() const;

private:
    std::map<std::string, boost::any> savedSettings;
    Settings();  // Private constructor to prevent instantiation
    Settings(const Settings&) = delete;  // Delete copy constructor
    Settings& operator=(const Settings&) = delete;  // Delete assignment operator
};

#endif
