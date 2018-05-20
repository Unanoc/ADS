#ifndef ASD_3_1_1_CSETGRAPH_H
#define ASD_3_1_1_CSETGRAPH_H

#include <vector>
#include <unordered_set>
#include "IGraph.h"

class CSetGraph : public IGraph {
public:
    explicit CSetGraph(unsigned long count);
    explicit CSetGraph(const IGraph &graph);

    ~CSetGraph() override;

    void AddEdge(int from, int to) override;

    unsigned long VerticesCount() const override;

    void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;
private:
    std::vector<std::unordered_set<int>> listHashTables;
};

#endif