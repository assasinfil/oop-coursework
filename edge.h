//
// Created by assasinfil on 01.11.2020.
//

#ifndef OOP_KURSACH_EDGE_H
#define OOP_KURSACH_EDGE_H

#include <ostream>

class Edge {
public:
    Edge();

    virtual ~Edge();

    friend std::ostream &operator<<(std::ostream &os, const Edge &edge);
};

#endif //OOP_KURSACH_EDGE_H
