//
// Created by assasinfil and polyaria on 01.11.2020.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <ostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

class Graph {
public:
    enum {
        Ford_Fulkerson,
        Edmonds_Karp,
        Dinits_alg
    };

    explicit Graph(int n);

    [[maybe_unused]] Graph(const Graph &other);

    Graph &operator=(const Graph &op);

    int EdmondsKarp(int source, int target);

    int FordFulkerson(int source, int target);

    std::vector<int> Bfs(int source);

    int Dfs(int source, int flow, int target, std::vector<int> dist, std::vector<int> p);

    int Dinits(int source, int target);

    int maxFlow(int source, int target, int type);

    virtual ~Graph();

    friend std::ostream &operator<<(std::ostream &os, const Graph &graph);

    friend std::istream &operator>>(std::istream &is, Graph &graph);

private:
    int count;
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> residualGraph;


};

#endif //GRAPH_H
