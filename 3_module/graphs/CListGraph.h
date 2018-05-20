#ifndef ASD_3_1_1_CLISTGRAPH_H
#define ASD_3_1_1_CLISTGRAPH_H

#include <vector>
#include "IGraph.h"

class CListGraph : public IGraph {
public:
    explicit CListGraph(unsigned long count);
    explicit CListGraph(const IGraph &graph);

    ~CListGraph() override;

    void AddEdge(int from, int to) override;

    unsigned long VerticesCount() const override;

    void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;
private:
    std::vector<std::vector<int>> adjacencyLists;
};

#endif