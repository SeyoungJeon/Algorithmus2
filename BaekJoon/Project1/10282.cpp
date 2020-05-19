#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

vector<pair<int, int>> graph[10001];
int dist[10001];

void Dijkstra(int start) {
	fill_n(dist, 10001, 1e8);
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

			if (nextCost < dist[next]){
				dist[next] = nextCost;
				pq.push({ -nextCost,next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int test;
	cin >> test;
	while (test--) {
		int n, d, c;
		
		cin >> n >> d >> c;
		for (int i = 0; i <= n; i++)
			graph[i].clear();

		for (int i = 0; i < d; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			graph[b].push_back({ s,a });
		}

		Dijkstra(c);
		int time = -1,cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (dist[i] < 1e8)
				cnt++;

			if (time < dist[i] && dist[i] < 1e8)
				time = dist[i];
		}

		cout << cnt << ' ' << time << '\n';
	}
	return 0;
}