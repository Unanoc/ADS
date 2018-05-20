/*
 Необходимо написать несколько реализаций интерфейса:
 CListGraph, хранящий граф в виде массива списков смежности,
 CMatrixGraph, хранящий граф в виде матрицы смежности,
 CSetGraph, хранящий граф в виде массива хэш-таблиц,
 CArcGraph, хранящий граф в виде одного массива пар {from, to}.
 Также необходимо реализовать конструктор, принимающий const IGraph*. Такой конструктор должен скопировать переданный граф в создаваемый объект.
 Для каждого класса создавайте отдельные h и cpp файлы.
 Число вершин графа задается в конструкторе каждой реализации.
*/

#include <iostream>
#include <vector>
#include <queue>

#include "CListGraph.h"
#include "CMatrixGraph.h"
#include "CArcGraph.h"
#include "CSetGraph.h"

void BFS(const IGraph& graph, int vertex, void (*visit)(int))
{
    std::vector<bool> visited(graph.VerticesCount(), false);
    std::queue<int> q;
    q.push(vertex);
    visited[vertex] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        visit(current);
        std::vector<int> adjacentVertices;
        graph.GetNextVertices(current, adjacentVertices);
        for (int i = 0; i < adjacentVertices.size(); i++) {
            if (!visited[adjacentVertices[i]]) {
                q.push(adjacentVertices[i]);
                visited[adjacentVertices[i]] = true;
            }
        }
    }
}


int main() {
    CListGraph graph(7);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 5);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(1, 5);
    graph.AddEdge(1, 6);
    graph.AddEdge(3, 2);
    graph.AddEdge(3, 6);
    graph.AddEdge(4, 3);
    graph.AddEdge(5, 4);
    graph.AddEdge(5, 6);
    graph.AddEdge(6, 4);

    BFS(graph, 0, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;

    CMatrixGraph m_graph(graph);
    BFS(m_graph, 0, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;

    CSetGraph s_graph(graph);
    BFS(s_graph, 0, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;

    CArcGraph a_graph(graph);
    BFS(a_graph, 0, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    return 0;
}