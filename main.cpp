  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

#include <vector>
#include <string>
#include <iostream>
using namespace std;

using namespace std;

struct Node {
    int value;
    vector<Node*> edge;
    int sum = 0;
};

int find_target_in_sub_tree(Node* now, vector<bool>& visited, const int& target) {
    visited[now->value] = true;
    now->sum = now->value;
    for (Node* next : now->edge) {
        if (visited[next->value]) continue;
        int result = find_target_in_sub_tree(next, visited, target);
        if (result != -1) return result;
        now->sum ^= next->sum;
    }

    if (now->value != 0 && now->sum == target) {
        return now->value;
    } else {
        return -1;
    }
}

bool can_partition(Node* nodes, int n, const int& target) {
    vector<bool> visited(n, false);
    if (find_target_in_sub_tree(&nodes[0], visited, target) == -1) return false;
    if (find_target_in_sub_tree(&nodes[0], visited, target) == -1) return false;
    return true;
}

string solve_test_case(int n, int k, vector<Node>& nodes) {
    int target = 0;
    for (int i = 0; i < n; i++) target ^= nodes[i].value;

    if (target == 0 || (k != 2 && can_partition(nodes.data(), n, target))) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() { 
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<Node> nodes(n);
        for (int i = 0; i < n; i++) {
            nodes[i].value = i;
            cin >> nodes[i].value;
        }
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            nodes[u].edge.push_back(&nodes[v]);
            nodes[v].edge.push_back(&nodes[u]);
        }

        cout << solve_test_case(n, k, nodes) << '\n';
    }
    return 0;
}

