#include <iostream>
#include <queue>
#include <limits.h>
#include <vector>

using namespace std;

vector<pair<int, int>> graph[20001];
int V, E, dis[20001],start;

void Dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	dis[start] = 0;

	while (!pq.empty()) {
		int d = -pq.top().first;
		int num = pq.top().second;

		pq.pop();

		if (dis[num] < d)
			continue;

		for (int i = 0; i < graph[num].size(); i++) {
			int next = graph[num][i].second;
			int nextDis = d + graph[num][i].first;

			if (dis[next] > nextDis) {
				dis[next] = nextDis;
				pq.push({ -nextDis, next });
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E;
	cin >> start;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		graph[u].push_back({ w,v });
	}
	
	fill_n(dis, V + 1, INT_MAX);

	Dijkstra(start);

	for (int i = 1; i <= V; i++) {
		if (dis[i] == INT_MAX) cout << "INF" << '\n';
		else cout << dis[i] << '\n';
	}
	
	return 0;
}