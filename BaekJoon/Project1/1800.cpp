#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

struct Pos {
	int num;
	int cost;
};

struct cmp {
	bool operator()(Pos a, Pos b) {
		return a.cost > b.cost;
	}
};

vector<pair<int,int>> graph[1001];
int visit[1001], N, P, K;

bool BFS(int standard) {
	priority_queue<Pos, vector<Pos>, cmp> q;
	q.push({ 1,0 });
	fill_n(visit, 1001, INT_MAX);
	visit[1] = 0;

	// ����� �ּҷ� �湮 �迭�� cost ����
	while (!q.empty()) {
		int num = q.top().num;
		int cost = q.top().cost;

		q.pop();

		if (visit[num] < cost)
			continue;

		for (int i = 0; i < graph[num].size(); i++) {
			int next = graph[num][i].first;
			int nc = cost + (graph[num][i].second > standard);	// standard �̻����� �� �� �ִ��� ������ �Ǵ�

			if (visit[next] > nc) {
				visit[next] = nc;
				q.push({ next,nc });
			}
		}
	}

	return visit[N] <= K;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> P >> K;
	for (int i = 0; i < P; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		graph[s].push_back({ e,c });
		graph[e].push_back({ s,c });
	}

	int left = 0, right = 1e6, mid, answer = -1;

	// �̺� Ž�� (X�� ���Ϸ� ������ �� �ִ��� �Ǵ��ϱ� �� �߿��� �ִ� ã��)
	while (left <= right) {
		mid = left + (right - left) / 2;

		// 
		if (BFS(mid)) {
			answer = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	
	cout << answer << '\n';

	return 0;
}