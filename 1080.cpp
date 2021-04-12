#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct node_t {
	bool isCheched;
	bool color;
	vector<int> neighbors;
};

node_t nodes[99];
queue<int> q;
int n;
static int getNextX();
bool isColoringPosible();

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		int x;
		while ((x = getNextX()) != 0) {
			nodes[i].neighbors.push_back(x);
			nodes[x].neighbors.push_back(i);
		}
	}

	q.push(1);
	nodes[1].isCheched = true;
	nodes[1].color = 0;

	if (n != 0 && isColoringPosible()) {
		for (int i = 1; i <= n; ++i) {
			printf("%d", nodes[i].color);
		}
	} else {
		printf("-1");
	}

	getchar();
	getchar();
}
	
bool isColoringPosible() {

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < nodes[curr].neighbors.size();  ++i) {
			int next = nodes[curr].neighbors[i];
			if (!nodes[next].isCheched) {
				nodes[next].isCheched = true;
				nodes[next].color = nodes[curr].color == 0 ? 1 : 0;
				q.push(next);
			}
			else if (nodes[next].color == nodes[curr].color) {
				return false;
			}
		}
	}

	return true;
}

static int getNextX() {
	int x;
	scanf("%d", &x);
	return x;
}
