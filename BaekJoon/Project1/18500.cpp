#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> v;
char map[100][100];
int N, R,C, temp_map[100][100], dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
bool visit[100][100], cluster;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.first < b.first) {
		return true;
	}
	else if (a.first == b.first) {
		if (a.second >= b.second) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

struct Pos {
	int y;
	int x;
	int cnt;
};

int BFS() {
	queue<Pos> q;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			temp_map[i][j] = map[i][j];
		}
	}
	for (auto k : v) {
		temp_map[k.first][k.second] = 'o';
		q.push({ k.first,k.second,0 });
	}

	int result = R;
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;

		q.pop();

		int ny = y + 1, nx = x;
	
		if (ny == R || temp_map[ny][nx] == 'x')
			return cnt;

		if (temp_map[ny][nx] == 'o')
			continue;

		q.push({ ny,nx,cnt + 1 });
	}

	return result;
}

void DFS(int row, int col) {
	if (row == R - 1) {
		cluster = false;
		return;
	}

	visit[row][col] = true;
	v.push_back({ row,col });

	for (int i = 0; i < 4; i++) {
		int ny = row + dir[i][0];
		int nx = col + dir[i][1];

		if (ny < 0 || ny >= R || nx < 0 || nx >= C)
			continue;

		if (visit[ny][nx] || map[ny][nx] == '.')
			continue;

		DFS(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	cin >> N;
	for (int i = 0; i < N; i++) {
		int height,col;
		cin >> height;

		height = R - height;
		if (i % 2 == 0) {
			// 왼쪽에서 창 던짐
			col = 0;
			// 예외 제대로 처리하기
			while (col < C && map[height][col] != 'x') {
				col++;
			}
		}
		else {
			// 오른쪽에서 창 던짐
			col = C - 1;
			while (col >= 0 && map[height][col] != 'x') {
				col--;
			}
		}

		// 아무것도 부시지 않았을 때
		if (col == C || col == -1)
			continue;

		map[height][col] = '.';

		for (int i = 0; i < R; i++) {
			fill_n(visit[i], C, false);
		}

		cluster = false;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (!visit[i][j] && map[i][j] == 'x') {
					cluster = true;
					v.clear();
					DFS(i, j);

					if (cluster)
						break;
				}
			}
			if (cluster)
				break;
		}

		if (cluster) {

			// 떨어질 수 있는 최소거리 
			int result = BFS();

			for (auto k : v) {
				map[k.first][k.second] = '.';
			}

			for (auto k : v) {
				map[k.first + result][k.second] = 'x';
			}

		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}

	return 0;
}