#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

vector<pair<int, int>> graph[1001];
int N, M,dist[1001],path[1001];

void Dijkstra() {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,1 });
	fill_n(dist, 1001, INT_MAX);
	dist[1] = 0;

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

				path[next] = num;		// 최단 경로 저장
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		graph[A].push_back({ C,B });
		graph[B].push_back({ C,A });
	}

	Dijkstra();

	int cnt = 0;
	vector<pair<int, int>> an;
	for (int i = 1; i <= N; i++) {
		if (path[i] != 0){
			cnt++;
			an.push_back({ i,path[i] });
		}
	}

	cout << cnt << '\n';
	for (auto k : an) {
		cout << k.first << ' ' << k.second << '\n';
	}

	return 0;
}