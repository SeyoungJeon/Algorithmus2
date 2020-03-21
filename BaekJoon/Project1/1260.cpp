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

	// �湮�� ��� üũ
	check[curNode] = true;

	for (size_t i = 0; i < map[curNode].size(); i++) {
		int nextNode = map[curNode][i];

		// �̹� �湮�ߴ� ����� �ѱ��
		if (check[nextNode])
			continue;

		DFS(nextNode);
	}
}

void BFS(int curNode) {
	queue<int> q;

	// ���� ��� �ֱ�
	q.push(curNode);
	check[curNode] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		cout << cur << ' ';

		for (size_t i = 0; i < map[cur].size(); i++) {
			int next = map[cur][i];

			// �̹� �湮�� ����� �ѱ��
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
	
	// ����, ����, �������� �Է� �ޱ�
	cin >> N >> M >> V;

	// Map, �湮 ���� �ʱ�ȭ
	map = new vector<int>[N + 1];
	check = new bool[N + 1];
	fill_n(check, N + 1, false);

	for (int i = 0; i < M; i++) {
		int x1, x2;

		// ���� ���� �ޱ�
		cin >> x1 >> x2;

		map[x1].push_back(x2);
		map[x2].push_back(x1);

		// ���� �������� ����
		sort(map[x1].begin(), map[x1].end());
		sort(map[x2].begin(), map[x2].end());
	}

	// DFS 
	DFS(V);
	cout << '\n';

	// �湮 �迭 �ʱ�ȭ
	fill_n(check, N + 1, false);

	//BFS
	BFS(V);
	cout << '\n';

	delete[] map;
	delete[] check;

	return 0;
}