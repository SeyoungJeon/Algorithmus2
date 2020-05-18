#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> graph[1001];
int N, M, dist[1001], start, last;

void Dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	dist[start] = 0;

	while (!pq.empty()) {
		int num = pq.top().second;
		int cost = -pq.top().first;

		pq.pop();

		if (dist[num] < cost)
			continue;

		for (int i = 0; i < graph[num].size(); i++) {
			int next = graph[num][i].second;
			int nextCost = cost + graph[num][i].first;

			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				pq.push({ -nextCost,next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ w,v });
	}

	cin >> start >> last;

	fill_n(dist, N + 1, INT_MAX);
	Dijkstra(start);

	cout << dist[last] << '\n';

	return 0;
}