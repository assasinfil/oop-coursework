//
// Created by assasinfil on 01.11.2020.
//
#include <iostream>
#include <fstream>
#include "graph.h"

using namespace std;

int main() {
    ifstream f("input.txt");
    int x, y;
    f >> x >> y;
    Graph graph(y, x);
    f >> graph;
    cout << graph;
    return 0;
}
