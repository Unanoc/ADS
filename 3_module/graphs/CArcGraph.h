#ifndef ASD_3_1_1_CARCGRAPH_H
#define ASD_3_1_1_CARCGRAPH_H

#include <vector>
#include "IGraph.h"

class CArcGraph : public IGraph {
public:
    explicit CArcGraph(unsigned long count);
    explicit CArcGraph(const IGraph &graph);

    ~CArcGraph() override;

    void AddEdge(int from, int to) override;

    unsigned long VerticesCount() const override;

    void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;
private:
    unsigned long countVertices;
    std::vector<std::pair<int, int>> listPairs;
};

#endif