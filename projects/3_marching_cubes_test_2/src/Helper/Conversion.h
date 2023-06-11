#ifndef CONVERSION_H_MY
#define CONVERSION_H_MY
#include <string>
bool STBool(const std::string& str, bool& result);
bool STFloat(const std::string& str, float& result);
bool STDouble(const std::string& str, double& result);
bool STInt(const std::string& str, int& result);
#endif
