#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge {
	int s;
	int e;
	int cost;

	bool operator < (Edge &edge) {
		return this->cost < edge.cost;
	}
};

vector<Edge> v;
int parent[100001];

int Find(int num) {
	if (parent[num] == num)
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

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i <= N; i++)
		parent[i] = i;

	int answer = 0,temp = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!IsEqualSet(v[i].s, v[i].e)) {
			Union(v[i].s, v[i].e);
			answer += v[i].cost;
			temp = v[i].cost;
		}
	}

	// 최댓값 하나 삭제
	cout << answer - temp << '\n';
	return 0;
}