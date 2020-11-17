//
// Created by assasinfil on 01.11.2020.
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
    cout << graph;

    //cout << graph.maxFlow(0, 5, graph.Ford_Fulkerson);
    cout << graph.maxFlow(0, 5, graph.Edmonds_Karp);
    return 0;
}
