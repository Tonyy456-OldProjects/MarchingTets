#ifndef R_SETTINGS_H
#define R_SETTINGS_H

#include <map>
#include <string>
#include <typeinfo>
#include <iostream>
#include <boost/any.hpp>
#include <sys/stat.h>
#include <unistd.h>
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <filesystem>
#include "./Conversion.h"

class Settings {
public:
    static Settings& getInstance();
    bool Initialize();
    void Print() const;

    template<typename T>
    bool TryGetSetting(const std::string& key, T& value) const;
    template<typename T>
    T& GetSetting(const std::string& key, T& default_value) const;
    template <typename T>
    void SetSetting(const std::string& key, const T& value);

private:
    std::map<std::string, boost::any> savedSettings;
    Settings();  
    Settings(const Settings&) = delete;  
    Settings& operator=(const Settings&) = delete;  
};

#endif
