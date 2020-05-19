#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

vector<pair<int, int>> graph[801];
int N, E, dist[3][801], v1, v2, answer;

void Dijkstra(int i, int start) {
	fill_n(dist[i], 801, 987654321);
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	dist[i][start] = 0;

	while (!pq.empty()) {
		int num = pq.top().second;
		int cost = -pq.top().first;

		pq.pop();

		if (dist[i][num] < cost)
			continue;

		for (int j = 0; j < graph[num].size(); j++) {
			int next = graph[num][j].second;
			int nextCost = cost + graph[num][j].first;

			if (dist[i][next] > nextCost) {
				dist[i][next] = nextCost;
				pq.push({ -nextCost,next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> E;

	for (int i = 0; i < E; i++){
		int u, v, w;
		cin >> u >> v >> w;

		graph[u].push_back({ w,v });
		graph[v].push_back({ w,u });
	}

	cin >> v1 >> v2;

	Dijkstra(0, 1);
	Dijkstra(1, v1);
	Dijkstra(2, v2);
	
	int d1 = dist[0][v1] + dist[1][v2] + dist[2][N];
	int d2 = dist[0][v2] + dist[2][v1] + dist[1][N];

	answer = d1 < d2 ? d1 : d2;

	if (answer >= 987654321 || answer < 0) cout << -1 << '\n';
	else cout << answer << '\n';

	return 0;
}