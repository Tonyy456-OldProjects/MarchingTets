#ifndef R_SETTINGS_H
#define R_SETTINGS_H

#include <map>
#include <string>
#include <typeinfo>
#include <iostream>
#include <boost/any.hpp>

class Settings {
public:
    static Settings& getInstance();

    template <typename T>
    bool TryGetSetting(const std::string& key, T& value) const;

    template <typename T>
    void SetSetting(const std::string& key, const T& value);

    void Initialize(const std::string& filename);

    void Print() const;

private:
    std::map<std::string, boost::any> savedSettings;
    Settings();  // Private constructor to prevent instantiation
    Settings(const Settings&) = delete;  // Delete copy constructor
    Settings& operator=(const Settings&) = delete;  // Delete assignment operator
};

#endif
