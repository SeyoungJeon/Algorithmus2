#include <iostream>

using namespace std;

int N, max_val = 0 , ans = 0;
int map[100][100], dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
bool temp_map[100][100],check[100][100];

void SetMap(int height) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] <= height) {
				temp_map[i][j] = true;
			}
			else {
				temp_map[i][j] = false;
			}
		}
	}
}

void SetCheck() {
	for (int i = 0; i < N; i++) {
		fill_n(check[i], N, false);
	}
}

void DFS(int row, int col) {
	check[row][col] = true;

	for (int i = 0; i < 4; i++) {
		int ny = row + dir[i][0];
		int nx = col + dir[i][1];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N)
			continue;

		if (temp_map[ny][nx] || check[ny][nx])
			continue;

		DFS(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (max_val < map[i][j]) {
				max_val = map[i][j];
			}
		}
	}

	for (int i = 0; i <= max_val; i++) {
		SetMap(i);
		SetCheck();

		int result = 0;

		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) {
				if (temp_map[row][col])
					continue;

				if (check[row][col])
					continue;

				result++;
				DFS(row, col);
			}
		}

		if (ans < result)
			ans = result;
	}

	cout << ans << '\n';

	return 0;
}