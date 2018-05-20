#include "CArcGraph.h"

CArcGraph::CArcGraph(unsigned long count) : countVertices(count) {}

CArcGraph::CArcGraph(const IGraph &graph) {
    countVertices = graph.VerticesCount();
    std::vector<int> tempVertices;

    for (int from = 0; from < graph.VerticesCount(); from++) {
        graph.GetNextVertices(from, tempVertices);

        for (int to : tempVertices) {
            listPairs.emplace_back(from, to); // like a pushBack(std::make_pair(from, to));
        }
    }
}

CArcGraph::~CArcGraph() = default;

void CArcGraph::AddEdge(int from, int to) {
    listPairs.emplace_back(from, to);
    countVertices++;
}

unsigned long CArcGraph::VerticesCount() const {
    return countVertices;
}

void CArcGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    assert(vertex >= 0 && vertex < countVertices);
    vertices.clear();

    for (const auto &listPair : listPairs) {
        if (listPair.first == vertex) {
            vertices.push_back(listPair.second);
        }
    }
}

void CArcGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    assert(vertex >= 0 && vertex < countVertices);
    vertices.clear();

    for (const auto &listPair : listPairs) {
        if (listPair.second == vertex) {
            vertices.push_back(listPair.first);
        }
    }
}