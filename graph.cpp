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

Graph::Graph(const Graph &other) {
    length = other.length;
    width = other.width;

    if (other.matrix) {
        matrix = new int *[length];

        for (int i = 0; i < length; ++i)
            matrix[i] = new int[width];

        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < width; ++j) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }
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

//TODO operator=
//что тут не так?
/*Graph &Graph::operator=(const Graph &op) {
    length = op.length;
    width = op.width;

    if (op.matrix) {
        matrix = new int *[length];

        for (int i = 0; i < length; ++i)
            matrix[i] = new int[width];

        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < width; ++j) {
                matrix[i][j] = op.matrix[i][j];
            }
        }
    }
    return *this;
}*/



