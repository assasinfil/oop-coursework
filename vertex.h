//
// Created by assasinfil on 01.11.2020.
//

#ifndef OOP_KURSACH_VERTEX_H
#define OOP_KURSACH_VERTEX_H

#include <ostream>

class Vertex {
public:
    Vertex();

    virtual ~Vertex();

    friend std::ostream &operator<<(std::ostream &os, const Vertex &vertex);
};

#endif //OOP_KURSACH_VERTEX_H
