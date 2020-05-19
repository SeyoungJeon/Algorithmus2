#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

struct Pos {
	int z;
	int y;
	int x;
};

char map[30][30][30];
int dist[30][30][30], L, R, C, dir[6][3] = { {-1,0,0},{1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1} };
Pos s, e;

int Dijkstra() {
	priority_queue<pair<int, pair<int,pair<int,int>>>> pq;
	pq.push({ 0,{s.z,{s.y,s.x}} });
	dist[s.z][s.y][s.x] = 0;

	while (!pq.empty()) {
		int z = pq.top().second.first;
		int y = pq.top().second.second.first;
		int x = pq.top().second.second.second;
		int cost = -pq.top().first;

		pq.pop();

		if (dist[z][y][x] < cost)
			continue;

		for (int i = 0; i < 6; i++) {
			int nz = z + dir[i][0];
			int ny = y + dir[i][1];
			int nx = x + dir[i][2];

			if (nz < 0 || nz >= L || ny < 0 || ny >= R || nx < 0 || nx >= C)
				continue;

			if (map[nz][ny][nx] == '#')
				continue;

			int nextCost = dist[z][y][x] + 1;
			if (dist[nz][ny][nx] > nextCost) {
				dist[nz][ny][nx] = nextCost;
				pq.push({ -nextCost,{nz,{ny,nx}} });
			}
		}
	}

	return dist[e.z][e.y][e.x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> L >> R >> C) {
		if (L == 0 && R == 0 && C == 0)
			break;

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> map[i][j][k];
					if (map[i][j][k] == 'S') s = { i,j,k };
					if (map[i][j][k] == 'E') e = { i,j,k };
					dist[i][j][k] = INT_MAX;
				}
			}
		}

		int answer = Dijkstra();
		if (answer < 0 || answer >= INT_MAX) cout << "Trapped!" << '\n';
		else cout << "Escaped in " << answer << " minute(s).\n";
	}

	return 0;
}