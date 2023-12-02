import sys
from collections import  Counter, deque
class Graph:
    def __init__(self, jobs):
        self.nodes = {}
        for job in jobs:
            self.nodes[job] = []
        self.length = len(jobs)
    
    def add_edge(self, u, v):
        self.nodes[u].append(v)
    def topological_sort(self):
        queue = deque()
        indegree = Counter()
        for dep in self.nodes:
            for job in self.nodes[dep]: 
                indegree[job] += 1
        for node in self.nodes:
            if indegree[node] == 0:
                queue.append(node)
        res = []
        while len(queue) > 0:
            node = queue.pop()
            res.append(node)
            for job in self.nodes[node]:
                indegree[job] -= 1
                if indegree[job] == 0:
                    queue.append(job)
        for node in indegree:
            if indegree[node] > 0:
                return []
        return res


def topologicalSort(jobs, deps):
    graph = Graph(jobs)
    for dep, job in deps:
        graph.add_edge(dep, job)
    return graph.topological_sort()


def solve():
    deps=[
  [3, 1],
  [8, 1],
  [8, 7],
  [5, 7],
  [5, 2],
  [1, 4],
  [6, 7],
  [1, 2],
  [7, 6]
] 
    jobs= [1, 2, 3, 4, 5, 6, 7, 8]  
    print(topologicalSort(jobs, deps))
    




if __name__ == "__main__":
    if 'ONLINE_JUDGE' not in sys.argv:
        sys.stdin = open('.input', 'r')
   
        solve()
        



