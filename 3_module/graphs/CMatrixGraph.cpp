#include "CMatrixGraph.h"

CMatrixGraph::CMatrixGraph(unsigned long count) {
    adjacencyMatrix.resize(count);
    for (int row = 0; row < adjacencyMatrix.size(); row++) {
        adjacencyMatrix[row].resize(count);
        std::fill(adjacencyMatrix[row].begin(), adjacencyMatrix[row].end(), 0);
    }
}

CMatrixGraph::CMatrixGraph(const IGraph &graph) {
    adjacencyMatrix.resize(graph.VerticesCount());
    std::vector<int> tempVertices;

    for (int row = 0; row < adjacencyMatrix.size(); row++) {
        adjacencyMatrix[row].resize(graph.VerticesCount());
        std::fill(adjacencyMatrix[row].begin(), adjacencyMatrix[row].end(), 0);
        graph.GetNextVertices(row, tempVertices);

        for (int vertex : tempVertices) {
            adjacencyMatrix[row][vertex] = 1;
        }
    }
}

CMatrixGraph::~CMatrixGraph() = default;

void CMatrixGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < adjacencyMatrix.size());
    assert(to >= 0 && to < adjacencyMatrix.size());

    adjacencyMatrix[from][to] = 1;
}

unsigned long CMatrixGraph::VerticesCount() const {
    return adjacencyMatrix.size();
}

void CMatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    assert(vertex >= 0 && vertex < adjacencyMatrix.size());
    vertices.clear();

    for (int i = 0; i < adjacencyMatrix[vertex].size(); i++) {
        if (adjacencyMatrix[vertex][i] == 1) {
            vertices.push_back(i);
        }
    }
}

void CMatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    assert(vertex >= 0 && vertex < adjacencyMatrix.size());
    vertices.clear();

    for (int i = 0; i < adjacencyMatrix.size(); i++) {
        if (adjacencyMatrix[i][vertex] == 1) {
            vertices.push_back(i);
        }
    }
}