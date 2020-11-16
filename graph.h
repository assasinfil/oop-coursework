//
// Created by assasinfil on 01.11.2020.
//

#ifndef OOP_KURSACH_GRAPH_H
#define OOP_KURSACH_GRAPH_H

#include <iostream>
#include <ostream>
#include <queue>
#include <vector>

class Graph {
public:
    Graph(int n);

    Graph(const Graph &other);

    Graph &operator=(const Graph &op);

    int findTarget(int source, int target);

    int maxFlow(int source, int target);

    virtual ~Graph();

    friend std::ostream &operator<<(std::ostream &os, const Graph &graph);

    friend std::istream &operator>>(std::istream &is, Graph &graph);

private:
    int n;
    std::vector<std::vector<int>> matrix;
};

#endif //OOP_KURSACH_GRAPH_H
