//
// Created by assasinfil on 01.11.2020.
//

#include "graph.h"

Graph::Graph(int n) {
    count = n;
    matrix.resize(n);
    flowGraph.resize(n);
    for (int i = 0; i < n; ++i) {
        matrix[i].resize(n);
        flowGraph[i].resize(n);
    }
}

Graph::~Graph() {
    matrix.clear();
}

Graph::Graph(const Graph &other) {
    count = other.count;

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
        count = other.count;

        matrix.clear();
        copy(other.matrix.begin(), other.matrix.end(), back_inserter(matrix));
    }
    return *this;
}

std::istream &operator>>(std::istream &is, Graph &graph) {
    for (int i = 0; i < graph.count; ++i) {
        for (int j = 0; j < graph.count; ++j) {
            is >> graph.matrix[i][j];
        }
    }
    return is;
}

int Graph::maxFlow(int source, int target, int type = Edmonds_Karp) {
    int MaxFlow = 0;
    int AddFlow;
    do {
        switch (type) {
            case Ford_Fulkerson:
                AddFlow = FordFulkerson(source, target);
                break;
            default:
            case Edmonds_Karp:
                AddFlow = EdmondsKarp(source, target);
                break;
            case Dinitz:
//                AddFlow = Dinitz(source, target);
                break;
        }
        MaxFlow += AddFlow;
    } while (AddFlow > 0);
    return MaxFlow;
}

int Graph::FordFulkerson(int source, int target) {
    std::vector<int> flow(count, 0);
    std::vector<int> link(count, -1);
    flow[source] = INT_MAX;

    std::queue<int> q;
    q.push(source);
    while (link[target] == -1 && !q.empty()) {
        int vertex = q.front();
        q.pop();
        for (int i = 0; i < count; ++i) {
            if ((matrix[vertex][i] - flowGraph[vertex][i]) > 0 and flow[i] == 0) {
                q.push(i);
                link[i] = vertex;
                if (matrix[vertex][i] - flowGraph[vertex][i] < flow[vertex])
                    flow[i] = matrix[vertex][i];
                else
                    flow[i] = flow[vertex];
            }
        }
    }
    if (link[target] == -1) return 0;

    int vertex = target;
    while (vertex != source) {
        flowGraph[link[vertex]][vertex] += flow[target];
        vertex = link[vertex];
    }
    return flow[target];
}

int Graph::EdmondsKarp(int source, int target) {
    //TODO EdmondsKarp
//    std::queue<int> q;
//    q.push(source);
//    std::vector<bool> used(count, false);
//    std::vector<int> dist(count, INT_MAX);
//    used[source] = true;
//    dist[source] = 0;
//    while (!q.empty()) {
//        int vertex = q.front();
//        q.pop();
//        for (int i = 0; i < count; ++i) {
//            if (!used[i]) {
//                used[i] = true;
//                q.push(i);
//                dist[i] = dist[vertex] + 1;
//            }
//        }
//    }
//    return dist[target];
}