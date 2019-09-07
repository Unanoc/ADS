#include "CSetGraph.h"

CSetGraph::CSetGraph(unsigned long count) {
    listHashTables.resize(count);
}

CSetGraph::CSetGraph(const IGraph &graph) {
    listHashTables.resize(graph.VerticesCount());
    std::vector<int> tempVertices;

    for (int from = 0; from < graph.VerticesCount(); from++) {
        graph.GetNextVertices(from, tempVertices);

        for (int to : tempVertices) {
            listHashTables[from].insert(to);
        }
    }
}

CSetGraph::~CSetGraph() = default;

void CSetGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < listHashTables.size());
    assert(to >= 0 && to < listHashTables.size());

    listHashTables[from].insert(to);
}

unsigned long CSetGraph::VerticesCount() const {
    return listHashTables.size();
}

void CSetGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    assert(vertex >= 0 && vertex < listHashTables.size());
    vertices.clear();

    for (const auto &elem : listHashTables[vertex]) {
        vertices.push_back(elem);
    }
}

void CSetGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    assert(vertex >= 0 && vertex < listHashTables.size());
    vertices.clear();

    for (int i = 0; i < listHashTables.size(); i++) {
        if (listHashTables[i].find(vertex) != listHashTables[i].end()) {
            vertices.push_back(i);
        }
    }
}
