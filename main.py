import sys



class Graph:
    def __init__(self, jobs):
        self.nodes = {}
        for job in jobs:
            self.nodes[job] = []
        self.length = len(jobs)
    
    def add_edge(self, u, v):
        self.nodes[u].append(v)
    def dfs(self, node, res, visited):
        if node in visited:
            return True      
        if len(self.nodes[node]) == 0:
            res.append(node)
            visited[node] = 2
            return True

        visited[node] = 1
        for dep in self.nodes[node]:
            if dep not in visited:           
                if not self.dfs(dep, res, visited):   
                    return False
            elif visited[dep] == 1 :
                    return False
                
        visited[node] = 2
        res.append(node)
            
        return True
        
    def topological_sort(self):
        res = []
        visited = {}
        for node in self.nodes:
            if not self.dfs(node,res, visited):
                return []
        return res
def topologicalSort(jobs, deps):
    graph = Graph(jobs)
    for v, u in deps:
        graph.add_edge(u, v)
    print(graph.nodes)
    return graph.topological_sort()


def solve():
    jobs = [1, 2, 3, 4, 5, 6, 7, 8] 
    deps =[
  [1, 2],
  [1, 3],
  [1, 4],
  [1, 5],
  [1, 6],
  [1, 7],
  [2, 8],
  [3, 8],
  [4, 8],
  [5, 8],
  [6, 8],
  [7, 8]
] 
    print(topologicalSort(jobs, deps))
    




if __name__ == "__main__":
    if 'ONLINE_JUDGE' not in sys.argv:
        sys.stdin = open('.input', 'r')
   
        solve()
        



