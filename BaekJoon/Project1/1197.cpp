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
int parent[10001], V, E;

int Find(int num) {
	if (num == parent[num])
		return num;
	return parent[num] = Find(parent[num]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	a < b ? parent[b] = a : parent[a] = b;
}

bool IsEqualSet(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		edges.push_back({ A,B,C });
	}

	sort(edges.begin(), edges.end());

	for (int i = 0; i <= V; i++)
		parent[i] = i;

	int answer = 0;
	for (auto edge : edges) {
		if (!IsEqualSet(edge.s, edge.e)) {
			answer += edge.cost;
			Union(edge.s, edge.e);
		}
	}

	cout << answer << '\n';
	return 0;
}
