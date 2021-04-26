#include <stdio.h>
#include <vector>
using namespace std;
struct edge_t {
  int a, b;
  double r, c;
};

vector<edge_t> edges;
int n, m, s;
double v;
double nodes[101];
bool solve();

int main() {
  int a, b;
  double rab, cab, rba, cba;
  scanf("%d %d %d %lf", &n, &m, &s, &v);
  nodes[s] = v;
  edges.reserve(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d %lf %lf %lf %lf", &a, &b, &rab, &cab, &rba, &cba);
    edges.push_back({a, b, rab, cab});
    edges.push_back({b, a, rba, cba});
  }
  if (solve()) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}

bool solve() {
  for (int i = 0; i < n - 1; ++i) {
    for (size_t j = 0; j < edges.size(); ++j) {
      nodes[edges[j].b] = max(nodes[edges[j].b], (nodes[edges[j].a] - edges[j].c) * edges[j].r);
    }
  }
  for (size_t i = 0; i < edges.size(); ++i) {
    if ((nodes[edges[i].a] - edges[i].c) * edges[i].r > nodes[edges[i].b])
      return true;
  }
  return false;
}