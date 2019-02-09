#ifndef ASD_3_1_1_CMATRIXGRAPH_H
#define ASD_3_1_1_CMATRIXGRAPH_H

#include <vector>
#include "IGraph.h"

class CMatrixGraph : public IGraph {
public:
    explicit CMatrixGraph(unsigned long count);
    explicit CMatrixGraph(const IGraph &graph);

    ~CMatrixGraph() override;

    void AddEdge(int from, int to) override;

    unsigned long VerticesCount() const override;

    void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;
private:
    std::vector<std::vector<int>> adjacencyMatrix;
};

#endif