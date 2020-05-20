#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pos {
	int num, x, y, z;
};

struct Edge {
	int s;
	int e;
	int cost;

	bool operator < (Edge &edge) {
		return this->cost < edge.cost;
	}
};

vector<Pos> p;
vector<Edge> edges;
int N, parent[100001];

bool compareX(Pos a, Pos b) {
	return a.x < b.x;
}

bool compareY(Pos a, Pos b) {
	return a.y < b.y;
}

bool compareZ(Pos a, Pos b) {
	return a.z < b.z;
}

int Find(int num) {
	if (parent[num] == num)
		return num;
	return parent[num] = Find(parent[num]);
}

bool Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b)
		return false;
	parent[a] = b;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		p.push_back({ i+1,a,b,c });
	}

	/*  각 축(X,Y,Z)끼리 오름차순 정렬해서 
		해당 축끼리 간선 저장 후, 
		Kruskal 알고리즘을 통해서 정답 도출
	*/
	sort(p.begin(), p.end(), compareX);
	for (int i = 0; i < p.size() - 1; i++) {
		int cost = abs(p[i].x - p[i + 1].x);
		edges.push_back({ p[i].num,p[i + 1].num,cost });
	}

	sort(p.begin(), p.end(), compareY);
	for (int i = 0; i < p.size() - 1; i++) {
		int cost = abs(p[i].y - p[i + 1].y);
		edges.push_back({ p[i].num,p[i + 1].num,cost });
	}

	sort(p.begin(), p.end(), compareZ);
	for (int i = 0; i < p.size() - 1; i++) {
		int cost = abs(p[i].z - p[i + 1].z);
		edges.push_back({ p[i].num,p[i + 1].num,cost });
	}

	sort(edges.begin(), edges.end());
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}

	int answer = 0;
	for (auto k : edges) {
		if (Union(k.s, k.e)) {
			answer += k.cost;
		}
	}

	cout << answer << '\n';

	return 0;
}