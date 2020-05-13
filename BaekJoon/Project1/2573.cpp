#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

struct Pos {
	int y;
	int x;
};

int N, M, **m, dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
bool **visit;

void DFS(int row, int col) {
	visit[row][col] = true;

	for (int i = 0; i < 4; i++) {
		int ny = row + dir[i][0];
		int nx = col + dir[i][1];

		if (m[ny][nx] == 0)
			continue;

		if (visit[ny][nx])
			continue;

		DFS(ny, nx);
	}
}

int BFS(queue<Pos> q) {
	int time = 0;
	bool check = false;

	while (!q.empty()) {
		size_t size = q.size();
	
		for (int s = 0; s < size; s++) {
			int y = q.front().y;
			int x = q.front().x;

			q.pop();

			int zeroCnt = 0;
			for (int i = 0; i < 4; i++) {
				int ny = y + dir[i][0];
				int nx = x + dir[i][1];

				if (m[ny][nx] == 0)
					zeroCnt++;
			}

			// 잠깐 다른 값으로 설정했다가
			if (m[y][x] - zeroCnt <= 0) {
				m[y][x] = -1;
			}
			else {
				m[y][x] -= zeroCnt;
				q.push({ y,x });
			}
		}
		
		// 여기서 복원
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (m[i][j] == -1) {
					m[i][j] = 0;
				}
			}
		}

		time++;

		for (int i = 0; i < N; i++) {
			fill_n(visit[i], M, false);
		}

		int island = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visit[i][j] && m[i][j] > 0) {
					DFS(i, j);
					island++;
				}

				if (island >= 2) {
					check = true;
					break;
				}
			}

			if (check) {
				break;
			}
		}

		if (check) {
			break;
		}
	}

	if (check) {
		return time;
	}
	else {
		return 0;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	queue<Pos> q;

	cin >> N >> M;

	m = new int*[N];
	visit = new bool*[N];
	for (int i = 0; i < N; i++) {
		m[i] = new int[M];
		visit[i] = new bool[M];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> m[i][j];
			if (m[i][j] > 0) {
				q.push({ i,j });
			}
		}
	}

	cout << BFS(q) << '\n';

	return 0;
}