#include <queue>
#include <unordered_map>
#include <unordered_set>
#ifndef online_judge
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;
using namespace std;
/**
 * Word Ladder
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.

Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.

sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

Constraints:

1 <= beginWord.length <= 10

endWord.length == beginWord.length

1 <= wordList.length <= 5000

wordList[i].length == beginWord.length

beginWord, endWord, and wordList[i] consist of lowercase English letters.

beginWord != endWord

All the words in wordList are unique.

Input : beginWord = "hit", endWord = "cog",  wordList = {"hot","dot","dog","lot","log","cog"}
Output : 5
Expected Time Complexity: O( 26*n*m^2)

here, m is the length of each word and n is the total number of words


*/
class Node {

public:
  string word;
  bool visited = false;
  int distance;
  vector<Node *> neighbours;

  Node(string word, int distance = -1) {
    this->word = word;
    this->distance = distance;
  }
  void add_neighbor(Node *node) { this->neighbours.push_back(node); }

};
class Graph {

  unordered_map<string, Node *> word_dict;
  void add_edge(string u, string v) {
    Node *node_u = word_dict[u], *node_v = word_dict[v];
    node_u->add_neighbor(node_v);
    node_v->add_neighbor(node_u);
  }

public:
  void add_node(string s) {
    Node *node = new Node(s);
    word_dict[s] = node;
  }
  int bfs(string beginWord, string endWord) {
    queue<Node *> q;
    word_dict[beginWord]->distance = 0;
    int m = beginWord.size();
    q.push(word_dict[beginWord]);
    while (!q.empty()) {
      auto node = q.front();
      q.pop();
      node->visited = true;
      string s = node->word;
      if (s == endWord) {
        break;
      }
      for (int i = 0; i < m; i++) {
        string word = s;

        for (int j = 0; j < 26; j++) {
          char c = char(int('a') + j);
          word[i] = c;

          if (word_dict.find(word) != word_dict.end() &&
              !word_dict[word]->visited) {
            word_dict[word]->distance = node->distance + 1;
            word_dict[word]->visited = true;

            add_edge(s, word);
            q.push(word_dict[word]);
          }
        }
      }
    }
    auto endNode = *word_dict[endWord];
    return endNode.distance + 1;
  }
};

int ladderLength(string beginWord, string endWord, vector<string> wordList) {
  const int m = beginWord.size();
  vector<vector<int>> table(m, vector<int>(26));
  Graph g;
  g.add_node(beginWord);
  for (auto word : wordList) {
    g.add_node(word);
  }
  return g.bfs(beginWord, endWord);

}

using namespace std;
void solve() {
  string beginWord = "hit", endWord = "cog";
  vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

  cout << ladderLength(beginWord, endWord, wordList);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();

  return 0;
}
