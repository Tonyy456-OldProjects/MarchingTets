#ifndef C_VECTOR_H
#define C_VECTOR_H

struct Vertex {
    double x;
    double y;
    double z;

    bool operator==(const Vertex& other) const {
        return (x == other.x && y == other.y && z == other.z);
    }
};

#endif
