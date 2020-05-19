#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> graph[500];
vector<int> trace[500];		// 해당 노드의 최단 경로로 연결된 노드와 비용
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

				// trace 비용이 더 작은 것이 등장했을 때
				trace[next].clear();
				trace[next].push_back(num);
			}
			else if (dist[next] == nextCost) {	// 최소 비용과 같을 때
				trace[next].push_back(num);
			}
		}
	}

	return dist[D];
}

void BFS() {
	// 거꾸로 연결된 것들 탐색
	queue<int> q;
	q.push(D);

	while (!q.empty()) {
		int num = q.front();

		q.pop();

		for (int i = 0; i < trace[num].size(); i++) {
			int next = trace[num][i];
			
			for (int j = 0; j < graph[next].size(); j++) {
				if (graph[next][j].second == num) {
					// 기존 그래프의 연결되어 있던 노드 비용 -1로 설정
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