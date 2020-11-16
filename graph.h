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
    enum {
        Ford_Fulkerson,
        Edmonds_Karp,
        Dinitz
    };

    Graph(int n);

    Graph(const Graph &other);

    Graph &operator=(const Graph &op);

    int EdmondsKarp(int source, int target);

    int FordFulkerson(int source, int target);

    int maxFlow(int source, int target, int type);

    virtual ~Graph();

    friend std::ostream &operator<<(std::ostream &os, const Graph &graph);

    friend std::istream &operator>>(std::istream &is, Graph &graph);

private:
    int count;
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> flowGraph;
};

#endif //OOP_KURSACH_GRAPH_H
