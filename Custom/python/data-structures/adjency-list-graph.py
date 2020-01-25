class VertexExistException(Exception):
    pass

class Graph:
    def __init__(self):
        self.adj_list: dict = {}

    def add_vertex(self, vertex):
        if vertex  in self.adj_list:
            raise VertexExistException(f'Vertex {vertex} exists')
        
        self.adj_list[vertex]: set = set()

    def add_edge(self, src, dest, weight=1):
        if src not in self.adj_list:
            raise VertexExistException(f'Vertex {src} does not exist')
        if dest not in self.adj_list:
            raise VertexExistException(f'Vertex {dest} does not exist')

        self.adj_list[src].append((dest, weight))

    def display(self):
        for v in self.adj_list:
            edges = ""
            for e in self.adj_list[v]:
                edges += f'({e[0]}: [{e[1]}])'
            print(f'{v}: {edges}')

    # def depth_search(self):




graph = Graph()

graph.add_vertex(1)
graph.add_vertex(2)
graph.add_vertex(3)
graph.add_vertex(4)
graph.add_vertex(5)

graph.add_edge(1,3)
graph.add_edge(1,4)
graph.add_edge(2,5)
graph.add_edge(3,1)
graph.add_edge(4,5)
graph.add_edge(1,2)

graph.display()