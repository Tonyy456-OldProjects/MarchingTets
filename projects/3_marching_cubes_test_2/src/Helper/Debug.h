#ifndef MY_DEBUG_H
#define MY_DEBUG_H

#include <iostream>
#include "./Point.h"
#include <array> 
#include <vector>
#include <cstdio>

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

    void print(const std::string& value)
    {
        std::cout << value;
    }

    void print(const Point& value)
    {
        print_ele(value);
    }

    void print(const float& value)
    {
        printf("%.3f",value);
    }

    void print(const char* str)
    {
        std::cout << str;
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

    template <typename T, std::size_t N>
    void print(const T (&value)[N])
    {
        std::cout << "[";
        int count = std::end(value) - std::begin(value);
        for(int i = 0; i < count; i++)
        {
            print_ele(value[i]);
            if(i != count - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "]";
    }

    template <typename T>
    void print_ele(const T &ele)
    {
        std::cout << ele;
    }  

    void print_ele(const double &ele)
    {
        printf("%.1f",ele);
    }

    void print_ele(const float &ele)
    {
        printf("%.1f",ele);
    }

    void print_ele(const Point &ele)
    {
        std::cout << std::endl;
        std::cout << "(";
        print_ele(ele.x);
        std::cout << ",";
        print_ele(ele.y);
        std::cout << ",";
        print_ele(ele.z);
        std::cout << ")";
    }
    
};

// Declare the global debug object
extern Debug debug;

#endif
