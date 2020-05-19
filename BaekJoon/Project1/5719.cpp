#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> graph[500];
vector<int> trace[500];		// �ش� ����� �ִ� ��η� ����� ���� ���
int N, M, S, D, dist[500];

int Dijkstra() {
	fill_n(dist, 500, INT_MAX);
	priority_queue<pair<int,int>> pq;
	pq.push({ 0,S });
	dist[S] = 0;
	
	while (!pq.empty()) {
		int num = pq.top().second;
		int cost = -pq.top().first;
		
		pq.pop();

		if (dist[num] < cost)
			continue;

		for (int i = 0; i < graph[num].size(); i++) {
			int next = graph[num][i].second;
			int nextCost = cost + graph[num][i].first;

			if (graph[num][i].first == -1)
				continue;

			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				pq.push({ -nextCost,next });

				// trace ����� �� ���� ���� �������� ��
				trace[next].clear();
				trace[next].push_back(num);
			}
			else if (dist[next] == nextCost) {	// �ּ� ���� ���� ��
				trace[next].push_back(num);
			}
		}
	}

	return dist[D];
}

void BFS() {
	// �Ųٷ� ����� �͵� Ž��
	queue<int> q;
	q.push(D);

	while (!q.empty()) {
		int num = q.front();

		q.pop();

		for (int i = 0; i < trace[num].size(); i++) {
			int next = trace[num][i];
			
			for (int j = 0; j < graph[next].size(); j++) {
				if (graph[next][j].second == num) {
					// ���� �׷����� ����Ǿ� �ִ� ��� ��� -1�� ����
					graph[next][j].first = -1;
				}
			}

			q.push(next);

		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> N >> M) {
		if (N == 0 && M == 0)
			break;

		for (int i = 0; i < N; i++) {
			trace[i].clear();
			graph[i].clear();
		}

		cin >> S >> D;
		for (int i = 0; i < M; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			graph[u].push_back({ w,v });
		}

		Dijkstra();
		BFS();
		
		int answer = Dijkstra();

		if (answer < 0 || answer >= INT_MAX) cout << -1 << '\n';
		else cout << answer << '\n';
	}

	return 0;
}