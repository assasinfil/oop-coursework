//
// Created by assasinfil on 01.11.2020.
//

#ifndef OOP_KURSACH_GRAPH_H
#define OOP_KURSACH_GRAPH_H

#include <ostream>

class Graph {
public:
    Graph();

    virtual ~Graph();

    friend std::ostream &operator<<(std::ostream &os, const Graph &graph);
};

#endif //OOP_KURSACH_GRAPH_H
