#include <algorithm>
#ifndef online_judge
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;
struct Point {
  int x;
  int y;
  friend ostream &operator<<(ostream &os, const Point &p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
  }
  bool operator<(Point p) const {
    if (x == p.x)
      return y < p.y;
    return x < p.x;
  }
};
int angle(Point a, Point b, Point c) {
  return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y);
}
bool clockwise(Point a, Point b, Point c) { return angle(a, b, c) > 0; }
bool anti_clockwise(Point a, Point b, Point c) { return angle(a, b, c) < 0; }

vector<Point> convex_hull(vector<Point> &points) {
  int n = points.size();

  sort(points.begin(), points.end());
  Point first = points[0], last = points.back();
  vector<Point> up, down;
  up.push_back(first);
  down.push_back(first);
  for (int i = 1; i < n; i++) {
    if (i == n - 1 || clockwise(first, points[i], last)) {
      while (up.size() >= 2 &&
             !clockwise(up[up.size() - 2], up[up.size() - 1], points[i])) {
        up.pop_back();
      }
      up.push_back(points[i]);
    }
    if (i == n - 1 || anti_clockwise(first, points[i], last)) {
      while (down.size() >= 2 &&
             !anti_clockwise(down[down.size() - 2], down[down.size() - 1],
                             points[i])) {
        down.pop_back();
      }
      down.push_back(points[i]);
    }
  }
  vector<Point> res(up.begin(), up.end());
  for (int i = 1; i < down.size() - 1; i++) {
    res.push_back(down[i]);
  }
  return res;
}
void solve() {
  int n;
  cin >> n;
  vector<Point> points(n);
  for (int i = 0; i < n; i++)
    cin >> points[i].x >> points[i].y;

  auto res = convex_hull(points);
  print(res);
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
