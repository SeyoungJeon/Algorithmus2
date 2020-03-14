#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, V;
vector<int> *map;
bool *check;

void DFS(int curNode) {
	
	cout << curNode << ' ';

	// 방문한 노드 체크
	check[curNode] = true;

	for (size_t i = 0; i < map[curNode].size(); i++) {
		int nextNode = map[curNode][i];

		// 이미 방문했던 노드라면 넘기기
		if (check[nextNode])
			continue;

		DFS(nextNode);
	}
}

void BFS(int curNode) {
	queue<int> q;

	// 시작 노드 넣기
	q.push(curNode);
	check[curNode] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		cout << cur << ' ';

		for (size_t i = 0; i < map[cur].size(); i++) {
			int next = map[cur][i];

			// 이미 방문한 노드라면 넘기기
			if (check[next])
				continue;

			check[next] = true;
			q.push(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	// 정점, 간선, 시작지점 입력 받기
	cin >> N >> M >> V;

	// Map, 방문 여부 초기화
	map = new vector<int>[N + 1];
	check = new bool[N + 1];
	fill_n(check, N + 1, false);

	for (int i = 0; i < M; i++) {
		int x1, x2;

		// 간선 정보 받기
		cin >> x1 >> x2;

		map[x1].push_back(x2);
		map[x2].push_back(x1);

		// 간선 오름차순 정렬
		sort(map[x1].begin(), map[x1].end());
		sort(map[x2].begin(), map[x2].end());
	}

	// DFS 
	DFS(V);
	cout << '\n';

	// 방문 배열 초기화
	fill_n(check, N + 1, false);

	//BFS
	BFS(V);
	cout << '\n';

	delete[] map;
	delete[] check;

	return 0;
}