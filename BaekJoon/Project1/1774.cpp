#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct Pos {
	int num;
	int x;
	int y;
};

struct Edge {
	int s;
	int e;
	double cost;

	bool operator < (Edge &edge){
		return this->cost < edge.cost;
	}
};

vector<pair<int, int>> conn;
vector<Pos> pos;
vector<Edge> edges;
int N, M, parent[1001];

int Find(int num) {
	if (parent[num] == num) return num;
	return parent[num] = Find(parent[num]);
}

bool Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return false;
	parent[b] = a; return true;
}

double CalculateCost(double x1, double y1, double x2, double y2) {
	return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int x, y;
		cin >> x >> y;
		pos.push_back({ i,x,y });
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		conn.push_back({ a,b });
	}

	for (int i = 0; i < pos.size(); i++) {
		for (int j = i + 1; j < pos.size(); j++) {
			edges.push_back({ pos[i].num,pos[j].num,
				CalculateCost(pos[i].x,pos[i].y,pos[j].x,pos[j].y) });
		}
	}

	for (auto c : conn) {
		Union(c.first, c.second);
	}

	sort(edges.begin(), edges.end());

	double answer = 0;
	for (auto edge : edges) {
		if (Union(edge.s, edge.e)) {
			answer += edge.cost;
		}
	}
	
	cout << fixed;
	cout.precision(2);
	cout << answer << '\n';

	return 0;
}