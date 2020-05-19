#include <iostream>
#include <limits.h>
#include <queue>

using namespace std;

int map[125][125], dist[125][125], N, dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

int Dijkstra() {
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0,{0,0} });
	dist[0][0] = map[0][0];

	while (!pq.empty()) {
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		int cost = -pq.top().first;
		
		pq.pop();

		if (dist[y][x] < cost)
			continue;

		for (int i = 0; i < 4; i++) {
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;

			int nextCost = dist[y][x] + map[ny][nx];
			if (dist[ny][nx] > nextCost) {
				dist[ny][nx] = nextCost;
				pq.push({ -nextCost,{ny,nx} });
			}
		}
	}

	return dist[N - 1][N - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cnt = 1;
	while (cin >> N) {
		if (N == 0)
			break;

		for (int i = 0; i < N; i++) {
			fill_n(dist[i], N, INT_MAX);
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		cout << "Problem " << cnt << ": " << Dijkstra() << '\n';

		cnt++;
	}

	return 0;
}