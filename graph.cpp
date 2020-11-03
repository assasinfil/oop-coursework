//
// Created by assasinfil on 01.11.2020.
//

#include "graph.h"


class Vertex {
public:
    Vertex();

    virtual ~Vertex();

    friend std::ostream &operator<<(std::ostream &os, const Vertex &vertex);
};

class Edge {
public:
    Edge();

    virtual ~Edge();

    friend std::ostream &operator<<(std::ostream &os, const Edge &edge);
};

//TODO add parameters
Graph::Graph() {}

//TODO add destruction
Graph::~Graph() {

}

//TODO complete format output
std::ostream &operator<<(std::ostream &os, const Graph &graph) {
    return os;
}
