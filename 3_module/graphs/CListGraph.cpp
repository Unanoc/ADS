#include "CListGraph.h"

CListGraph::CListGraph(unsigned long count) {
    adjacencyLists.resize(count);
}

CListGraph::CListGraph(const IGraph &graph) {
    adjacencyLists.resize(graph.VerticesCount());

    for (int from = 0; from < adjacencyLists.size(); from++) {
        graph.GetNextVertices(from, adjacencyLists[from]);
    }
}

CListGraph::~CListGraph() = default;

void CListGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < adjacencyLists.size());
    assert(to >= 0 && to < adjacencyLists.size());

    adjacencyLists[from].push_back(to);
}

unsigned long CListGraph::VerticesCount() const {
    return adjacencyLists.size();
}

void CListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    assert(vertex >= 0 && vertex < adjacencyLists.size());
    vertices.clear();

    vertices = adjacencyLists[vertex];
}

void CListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    assert(vertex >= 0 && vertex < adjacencyLists.size());
    vertices.clear();

    for (int from = 0; from < adjacencyLists.size(); from++) {
        for (int i = 0; i < adjacencyLists[from].size(); i++) {
            if (adjacencyLists[from][i] == vertex) {
                vertices.push_back(from);
            }
        }
    }
}