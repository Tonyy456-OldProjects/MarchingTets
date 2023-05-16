#ifndef MY_DEBUG_H
#define MY_DEBUG_H

#include <iostream>

class Debug {
public:
    template <typename T>
    Debug& operator<<(const T& value) {
        print(value);
        return *this;
    }
    
    template <typename T>
    void operator()(const T& value) {
        print(value);
        std::cout << std::endl;
    }
    
private:
    template <typename T>
    void print(const T& value) {
        std::cout << value;
    }
    
    void print(const std::vector<int>& value) {
        std::cout << "[";
        for (size_t i = 0; i < value.size(); ++i) {
            std::cout << value[i];
            if (i != value.size() - 1)
                std::cout << ", ";
        }
        std::cout << "]";
    }
    
    template <typename T>
    void print(const std::vector<T>& value) {
        std::cout << "[";
        for (size_t i = 0; i < value.size(); ++i) {
            std::cout << value[i];
            if (i != value.size() - 1)
                std::cout << ", ";
        }
        std::cout << "]";
    }
};
// Declare the global debug object
extern Debug debug;

#endif
