//
// Created by assasinfil on 01.11.2020.
//

#include "graph.h"


void free_matrix(int **matrix, int length) {
    if (matrix != nullptr) {
        for (int i = 0; i < length; ++i) {
            delete[] matrix[i];
        }
        delete matrix;
    }
}

int **create_matrix(int **matrix, int length, int width) {
    matrix = new int *[length];
    for (int i = 0; i < length; ++i) {
        matrix[i] = new int[width];
    }
    return matrix;
}

Graph::Graph(int y, int x) {
    length = y;
    width = x;

    matrix = create_matrix(matrix, length, width);

    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            matrix[i][j] = 0;
        }
    }
}

Graph::~Graph() {
    free_matrix(matrix, length);
}

Graph::Graph(const Graph &other) {
    length = other.length;
    width = other.width;

    if (other.matrix != nullptr) {
        matrix = create_matrix(matrix, length, width);

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

Graph &Graph::operator=(const Graph &op) {
    if (this != &op) {
        length = op.length;
        width = op.width;

        if (op.matrix != nullptr) {
            if (matrix != nullptr) {
                free_matrix(matrix, length);
            }
            matrix = create_matrix(matrix, length, width);

            for (int i = 0; i < length; ++i) {
                for (int j = 0; j < width; ++j) {
                    matrix[i][j] = op.matrix[i][j];
                }
            }
        }
    }
    return *this;
}

std::istream &operator>>(std::istream &is, Graph &graph) {
    for (int i = 0; i < graph.length; ++i) {
        for (int j = 0; j < graph.width; ++j) {
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
    //TODO findTarget
    return 0;
}



