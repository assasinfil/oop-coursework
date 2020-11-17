//
// Created by assasinfil on 01.11.2020.
//

#include "graph.h"

Graph::Graph(int n) {
    count = n;
    matrix.resize(n);
    residualGraph.resize(n);
    for (int i = 0; i < n; ++i) {
        matrix[i].resize(n);
        residualGraph[i].resize(n);
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
            if ((matrix[vertex][i] - residualGraph[vertex][i]) > 0 and flow[i] == 0) {
                q.push(i);
                link[i] = vertex;
                if (matrix[vertex][i] - residualGraph[vertex][i] < flow[vertex])
                    flow[i] = matrix[vertex][i];
                else
                    flow[i] = flow[vertex];
            }
        }
    }
    if (link[target] == -1) return 0;

    int vertex = target;
    while (vertex != source) {
        residualGraph[link[vertex]][vertex] += flow[target];
        vertex = link[vertex];
    }
    return flow[target];
}

int Graph::EdmondsKarp(int source, int target) {
    //TODO EdmondsKarp
    std::queue<int> q;
    q.push(source);
    std::vector<int> used(count, 0);
    std::vector<int> dist(count, INT_MAX);
    std::vector<int> path(count, -1);
    dist[source] = 0;
    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        if (used[vertex] == 2)
            continue;
        used[vertex] = 2;

        for (int i = target; i >= 0; i--) {
            if ((matrix[vertex][i] - residualGraph[vertex][i]) > 0 && used[i] != 2)//есть связь и вершина не обработана
            {
                if (dist[i] > dist[vertex] + 1) {
                    dist[i] = dist[vertex] + 1;
                    path[i] = vertex;
                }
                q.push(i);
                used[i] = 1;
            }
        }
    }
    std::vector<int> pathToTarget;
    int minFlow = INT_MAX;
    int nextPath = target;
    while (nextPath != -1) {
        pathToTarget.insert(pathToTarget.begin(), nextPath);
        nextPath = path[nextPath];
    }
    for (int i = 0; i < pathToTarget.size() - 1; ++i) {
        int minFlowW =
                matrix[pathToTarget[i]][pathToTarget[i + 1]] - residualGraph[pathToTarget[i]][pathToTarget[i + 1]];
        if (minFlow > minFlowW and minFlowW > 0) {
            minFlow = minFlowW;
        }
    }
    for (int i = 0; i < pathToTarget.size() - 1; ++i) {
        residualGraph[pathToTarget[i]][pathToTarget[i + 1]] = minFlow;
    }
    if (minFlow == INT_MAX) return 0;
    return minFlow;
}