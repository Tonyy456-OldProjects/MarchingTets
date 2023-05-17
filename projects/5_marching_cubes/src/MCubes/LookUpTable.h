#ifndef LOOKUP_TABLE_H
#define LOOKUP_TABLE_H

#include <array>
#include <vector>

const int TABLE_SIZE = 256;

// Lookup table with integers
extern std::array<int, TABLE_SIZE> edgeTable ;

// Lookup table with array of integers
extern std::array<std::vector<int>, TABLE_SIZE> triangleIndex ;


#endif
