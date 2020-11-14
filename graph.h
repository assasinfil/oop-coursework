//
// Created by assasinfil on 01.11.2020.
//

#ifndef OOP_KURSACH_GRAPH_H
#define OOP_KURSACH_GRAPH_H

#include <iostream>
#include <ostream>

class Graph {
public:
    Graph(int y, int x);

    Graph(const Graph& other);

    Graph &operator=(const Graph &op);

    virtual ~Graph();

    friend std::ostream &operator<<(std::ostream &os, const Graph &graph);

    friend std::istream &operator>>(std::istream &is, Graph &graph);

private:
    int length, width;
    int **matrix = nullptr;
};

#endif //OOP_KURSACH_GRAPH_H
