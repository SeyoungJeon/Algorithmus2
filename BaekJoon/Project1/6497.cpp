#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	int s;
	int e;
	int cost;

	bool operator < (Edge &edge) {
		return this->cost < edge.cost;
	}
};

vector<Edge> edges;
int m, n, parent[200000];

int Find(int num) {
	if (parent[num] == num)	return num;
	return parent[num] = Find(parent[num]);
}

bool Union(int a, int b) {
	a = Find(a); b = Find(b);
	if (a == b) return false;
	parent[b] = a; return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> m >> n) {
		if (m == 0 && n == 0)
			break;

		edges.clear();

		int allCost = 0;
		for (int i = 0; i < n; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			edges.push_back({ u,v,w });
			allCost += w;
		}

		for (int i = 0; i < m; i++)
			parent[i] = i;

		sort(edges.begin(), edges.end());

		int minCost = 0;
		for (auto k : edges) {
			if (Union(k.s, k.e)) {
				minCost += k.cost;
			}
		}
		
		int answer = allCost - minCost;
		cout << answer << '\n';
	}

	return 0;
}