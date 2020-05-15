#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>

using namespace std;


struct Edge {
	int start;
	int end;
	int cost;
};

int N, C;
vector<pair<int, int>> temp;
vector<Edge> graph;


bool compare(const Edge &a, const Edge &b) {
	return a.cost < b.cost;
}
// �θ��带 ������ 
int getParent(int parent[], int node) {
	if (parent[node] == node) {
		return node;
	}
	return getParent(parent, parent[node]);
}

// �� ����� �θ��带 ��ħ 
int unionParent(int parent[], int x, int y) {
	x = getParent(parent, x);
	y = getParent(parent, y);
	if (x < y) {
		parent[y] = x;
		return x;
	}
	else {
		parent[x] = y;
		return y;
	}
}

// ���� �θ��带 ������ Ȯ�� 
int findParent(int parent[], int x, int y) {
	x = getParent(parent, x);
	y = getParent(parent, y);
	if (x == y) {
		// ���� �θ� ��� 
		return 1;
	}
	else {
		// �ٸ� �θ� ��� 
		return 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		temp.push_back({ s,e });
	}

	for (int i = 0; i < N; i++) {
		int x1 = temp[i].first;
		int y1 = temp[i].second;

		for (int j = i + 1; j < N; j++) {
			int x2 = temp[j].first;
			int y2 = temp[j].second;

			int val = abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2);

			graph.push_back({ i,j,val });
		}
	}

	sort(graph.begin(), graph.end(), compare);

	int parent[2000];
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	int ans = 0,count = 0;
	for (int i = 0; i < graph.size(); i++) {
		if (graph[i].cost < C)
			continue;

		if (!findParent(parent, graph[i].start, graph[i].end)) {

			// ����Ŭ�� ������ ���� ���
			ans += graph[i].cost;

			// ���� �θ� ����Ű��
			unionParent(parent, graph[i].start, graph[i].end);
			count++;
		}
	}

	if (count != N - 1) {
		cout << -1 << '\n';
	}
	else {
		cout << ans << '\n';
	}

	return 0;
}