
from typing import List, Tuple
import math

def find_lowest_common_ancestor(n: int, edges: List[Tuple[int, int]], queries: List[Tuple[int, int]]) -> List[int]:
    """Find the Lowest Common Ancestor (LCA) for each query."""
    MAX_LOG = math.ceil(math.log2(n))
    
    # Initialize parent pointers and depths based on the number of nodes (n)
    parents = [[0 for _ in range(MAX_LOG)] for _ in range(n + 1)]
    node_depths = [0 for _ in range(n + 1)]
    
    # Initialize adjacency list for the graph
    adjacency_list = [[] for _ in range(n + 1)]

    def dfs(current_node: int, parent_node: int) -> None:
        """Populate parent pointers and depths using DFS."""
        parents[current_node][0] = parent_node
        node_depths[current_node] = node_depths[parent_node] + 1
        
        for log in range(1, MAX_LOG):
            parents[current_node][log] = parents[parents[current_node][log - 1]][log - 1]
        
        for neighbor in adjacency_list[current_node]:
            if neighbor != parent_node:
                dfs(neighbor, current_node)

    def initialize_graph(edges: List[Tuple[int, int]]) -> None:
        """Initialize the graph's adjacency list."""
        for u, v in edges:
            adjacency_list[u].append(v)
            adjacency_list[v].append(u)  # Bidirectional graph

    # Main logic starts here
    results = []
    initialize_graph(edges)
    
    node_depths[0] = -1
    dfs(1, 0)
    
    for u, v in queries:
        if u == v:
            results.append(u)
            continue
        
        if node_depths[u] < node_depths[v]:
            u, v = v, u
        
        depth_diff = node_depths[u] - node_depths[v]
        
        for i in range(MAX_LOG - 1, -1, -1):
            if depth_diff & (1 << i):
                u = parents[u][i]
        
        for i in range(MAX_LOG - 1, -1, -1):
            if parents[u][i] != parents[v][i]:
                u = parents[u][i]
                v = parents[v][i]
        
        ancestor = parents[u][0]
        if ancestor == 0:
            ancestor = 1
        results.append(ancestor)
    
    return results

# Example usage
n = 5
edges = [(1, 2), (1, 3), (3, 4), (3, 5)]
queries = [(4, 5), (2, 5), (1, 4)]

print(find_lowest_common_ancestor(n, edges, queries))
