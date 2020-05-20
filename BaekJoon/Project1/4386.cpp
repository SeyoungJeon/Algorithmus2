#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct Edge {
	int s;
	int e;
	float cost;
	
	bool operator < (Edge &edge) {
		return this->cost < edge.cost;
	}
};

struct Pos {
	int num;
	float x;
	float y;
};

vector<Pos> p;
vector<Edge> edges;
int n,parent[100];

int Find(int num) {
	if (parent[num] == num) return num;
	return parent[num] = Find(parent[num]);
}

bool Union(int a, int b) {
	a = Find(a); b = Find(b);
	if (a == b) return false;
	parent[b] = a; return true;
}

float CalculateDistance(float x1, float y1, float x2, float y2) {
	return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		float x, y;
		cin >> x >> y;
		p.push_back({i, x,y });
		parent[i] = i;
	}

	for (int i = 0; i < p.size(); i++) {
		for (int j = i + 1; j < p.size(); j++) {
			edges.push_back({ p[i].num,p[j].num,
				CalculateDistance(p[i].x,p[i].y,p[j].x,p[j].y) });
		}
	}

	sort(edges.begin(), edges.end());

	float minCost = 0;
	for (auto edge : edges) {
		if (Union(edge.s, edge.e)) {
			minCost += edge.cost;
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << minCost << '\n';

	return 0;
}