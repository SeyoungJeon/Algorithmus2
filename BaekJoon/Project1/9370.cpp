#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

void Dijkstra(vector<pair<int, int>> graph[], int s, int dist[], int n) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,s });
	fill_n(dist, n + 1, INT_MAX);
	dist[s] = 0;

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

	int T;
	cin >> T;
	while (T--) {
		vector<pair<int, int>> graph[2001];
		vector<int> candidate, answer;
		int n, m, t, s, g, h;
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		while (m--) {
			int a, b, d;
			cin >> a >> b >> d;
			graph[a].push_back({ d,b });
			graph[b].push_back({ d,a });
		}

		while (t--) {
			int input;
			cin >> input;
			candidate.push_back(input);
		}

		int dist1[2001], dist2[2001], value, res;
		Dijkstra(graph, s, dist1, n);
		if (dist1[g] < dist1[h]) {
			value = dist1[h];
			res = h;
		}
		else {
			value = dist1[g];
			res = g;
		}
		Dijkstra(graph, res, dist2, n);
		for (auto cand : candidate) {
			if (dist2[cand] + value == dist1[cand]) {
				answer.push_back(cand);
			}
		}

		sort(answer.begin(), answer.end());
		for (auto an : answer) {
			cout << an << ' ';
		}
		cout << '\n';
	}

	return 0;
}