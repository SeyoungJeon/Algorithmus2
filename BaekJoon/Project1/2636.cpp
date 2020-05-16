#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
int map[100][100], copy_map[100][100],N, M, dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} },cnt;
bool air,visit[100][100];

void DFS(int row,int col) {
	
	visit[row][col] = true;
	copy_map[row][col] = 1;
	
	for (int i = 0; i < 4; i++){
		int ny = row + dir[i][0];
		int nx = col + dir[i][1];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;

		if (visit[ny][nx])
			continue;

		if (map[ny][nx] == 1)
			continue;

		DFS(ny, nx);
	}
}

void CheckAir() {
	for (int i = 0; i < N; i++) {
		fill_n(visit[i], M, false);
	}

	for (int i = 0; i < N; i++) {
		// j = 0, j = M-1
		if (!visit[i][0] && map[i][0] == 0) {
			DFS(i, 0);
		}

		if (!visit[i][M - 1] && map[i][M - 1] == 0) {
			DFS(i, M - 1);
		}
	}
	for (int j = 0; j < M; j++) {
		// i = 0 , i = N-1
		if (!visit[0][j] && map[0][j] == 0) {
			DFS(0, j);
		}

		if (!visit[N - 1][j] && map[N - 1][j] == 0) {
			DFS(N - 1, j);
		}
	}
}

void PushData() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				for (int k = 0; k < 4; k++) {
					int ny = i + dir[k][0];
					int nx = j + dir[k][1];

					if (ny < 0 || ny >= N || nx < 0 || nx >= M
						|| copy_map[ny][nx] == 1) {
						q.push({ i,j });
						break;
					}
				}
			}
		}
	}
}

void BFS() {
	CheckAir();
	PushData();
	
	int time = 0,result;
	while (!q.empty()) {
		size_t size = q.size();
		result = size;
		for (int s = 0; s < size; s++) {
			int y = q.front().first;
			int x = q.front().second;

			q.pop();

			map[y][x] = 0;
		}
		
		CheckAir();
		PushData();
	
		time++;
	}

	cout << time << '\n';
	cout << result << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	BFS();
	
	return 0;
}