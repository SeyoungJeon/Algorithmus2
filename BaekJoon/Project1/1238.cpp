#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

vector<pair<int, int>> graph[2][1001];
int N, M, X, dist[2][1001];

void Dijkstra(int dir) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,X });
	
	while (!pq.empty()) {
		int num = pq.top().second;
		int cost = -pq.top().first;

		pq.pop();

		if (dist[dir][num] < cost)
			continue;

		for (int i = 0; i < graph[dir][num].size(); i++) {
			int next = graph[dir][num][i].second;
			int nextCost = cost + graph[dir][num][i].first;

			if (dist[dir][next] > nextCost) {
				dist[dir][next] = nextCost;
				pq.push({ -nextCost,next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> X;
	
	// 방향을 정해서 X를 기준으로 최소거리 구하면 됨
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[0][u].push_back({ w,v });		// 정방향
		graph[1][v].push_back({ w,u });		// 역방향
	}

	for (int i = 1; i <= N; i++) {
		dist[0][i] = INT_MAX;
		dist[1][i] = INT_MAX;
	}
	
	dist[0][X] = 0;
	dist[1][X] = 0;

	Dijkstra(0);
	Dijkstra(1);

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		if (answer < dist[0][i] + dist[1][i])
			answer = dist[0][i] + dist[1][i];
	}

	cout << answer << '\n';

	return 0;
}