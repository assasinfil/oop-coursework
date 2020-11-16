//
// Created by assasinfil on 01.11.2020.
//

#include "graph.h"

Graph::Graph(int n) {
    this->n = n;
    matrix.resize(n);
    for (int i = 0; i < n; ++i) {
        matrix[i].resize(n);
    }
}

Graph::~Graph() {
    matrix.clear();
}

Graph::Graph(const Graph &other) {
    this->n = other.n;

    matrix.clear();
    copy(other.matrix.begin(), other.matrix.end(), back_inserter(matrix));
}

std::ostream &operator<<(std::ostream &os, const Graph &graph) {
    for (const auto &row : graph.matrix) {
        for (const auto &item : row) {
            os << item << ' ';
        }
        os << std::endl;
    }
    return os;
}

Graph &Graph::operator=(const Graph &other) {
    if (this != &other) {
        this->n = other.n;

        matrix.clear();
        copy(other.matrix.begin(), other.matrix.end(), back_inserter(matrix));
    }
    return *this;
}

std::istream &operator>>(std::istream &is, Graph &graph) {
    for (int i = 0; i < graph.matrix.size(); ++i) {
        for (int j = 0; j < graph.matrix.size(); ++j) {
            is >> graph.matrix[i][j];
        }
    }
    return is;
}

int Graph::maxFlow(int source, int target) {
    int MaxFlow = 0;
    int AddFlow;
    do {
        AddFlow = findTarget(source, target);
        MaxFlow += AddFlow;
    } while (AddFlow > 0);
    return MaxFlow;
}

int Graph::findTarget(int source, int target) {
    std::queue<int> q;
    q.push(source);
    std::vector<bool> used(this->n);

    return 0;
}



