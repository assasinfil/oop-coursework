//
// Created by assasinfil on 01.11.2020.
//

#include "graph.h"


Graph::Graph(int y, int x) {
    length = y;
    width = x;
    matrix = new int *[y];
    for (int i = 0; i < y; ++i) {
        matrix[i] = new int[x];
    }
    //TODO load matrix
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            matrix[i][j] = 0;
        }
    }
}

Graph::~Graph() {
    for (int i = 0; i < length; ++i) {
        delete[] matrix[i];
    }
    delete matrix;
}

std::ostream &operator<<(std::ostream &os, const Graph &graph) {
    for (int i = 0; i < graph.length; ++i) {
        for (int j = 0; j < graph.width; ++j) {
            os << graph.matrix[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}

Graph::Graph(Graph *other) {
//TODO complete copy constructor
}
