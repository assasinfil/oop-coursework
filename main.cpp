//
// Created by assasinfil and polyaria on 01.11.2020.
//
#include <iostream>
#include <fstream>
#include "graph.h"

using namespace std;

int main() {
    ifstream f("input.txt");

    int n;
    f >> n;

    Graph graph(n);

    f >> graph;
    f.close();

    cout << graph << endl;

    for (auto i = 1; i < n; ++i) {
        cout << endl << i << ": ";
        cout << graph.maxFlow(0, i, graph.Ford_Fulkerson) << ", ";
        cout << graph.maxFlow(0, i, graph.Edmonds_Karp) << ", ";
        cout << graph.maxFlow(0, i, graph.Dinitz_alg) << ", ";
    }

    return 0;
}
