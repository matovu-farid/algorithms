
#include <iostream>
#include <vector>

using namespace std;

int dfs(int node, int parent, const vector<int>& values, const vector<vector<int>>& tree, int total_xor, int& count) {
    int xor_subtree = values[node];
    for (int child : tree[node]) {
        if (child != parent) {
            xor_subtree ^= dfs(child, node, values, tree, total_xor, count);
        }
    }
    if (xor_subtree == total_xor) {
        count++;
    }
    return xor_subtree;
}

string can_partition(int n, int k, const vector<int>& values, const vector<pair<int, int>>& edges) {
    int total_xor = 0;
    for (int value : values) {
        total_xor ^= value;
    }

    // Case when total XOR is 0
    if (total_xor == 0) {
        return "YES";
    }

    // Create a tree using adjacency list
    vector<vector<int>> tree(n + 1);
    for (const auto& edge : edges) {
        tree[edge.first].push_back(edge.second);
        tree[edge.second].push_back(edge.first);
    }

    // DFS to find XOR of subtrees
    int count = 0;
    dfs(1, -1, values, tree, total_xor, count);

    // Check conditions
    if (count >= 3 && k != 2) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> values(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> values[i];
        }
        vector<pair<int, int>> edges(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            cin >> edges[i].first >> edges[i].second;
        }
        cout << can_partition(n, k, values, edges) << '\n';
    }
    return 0;
}
