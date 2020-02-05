#include <iostream>
#include <deque>

using namespace std;

bool map[100][100];
bool check[100][100];

int N, M, dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
deque<pair<int, int>> q;

void DFS(int row,int col) {
	
	check[row][col] = true;

	for (int i = 0; i < 4; i++) {
		int ny = row + dir[i][0];
		int nx = col + dir[i][1];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;

		if (map[ny][nx] || check[ny][nx])
			continue;

		DFS(ny, nx);
	}
}

int BFS() {
	int result = 0;

	while (!q.empty()) {
		int size = q.size();
	
		for (int i = 0; i < N; i++) {
			fill_n(check[i], M, false);
		}

		DFS(0, 0);

		for (int i = 0; i < size; i++) {
			int cur_y = q.front().first;
			int cur_x = q.front().second;
			int border = 0;

			q.pop_front();

			for (int j = 0; j < 4; j++) {
				int ny = cur_y + dir[j][0];
				int nx = cur_x + dir[j][1];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M)
					continue;

				if (check[ny][nx]){
					border++;
				}
			}

			if (border < 2) {
				q.push_back({ cur_y,cur_x });
			}
			else {
				map[cur_y][cur_x] = false;
			}

		}
		result++;
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j]) {
				q.push_front({ i,j });
			}
		}
	}

	cout << BFS() << '\n';

	return 0;
}