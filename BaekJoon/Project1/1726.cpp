#include <iostream>
#include <queue>

#define RIGHT 1
#define LEFT 2
#define DOWN 3
#define UP 4

using namespace std;

struct Data {
	int y;
	int x;
	int dir;
	int cnt;
};

int N, M, ans = 987654321;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int cur_y, cur_x, cur_dir;
int des_y, des_x, des_dir;
bool map[100][100], check[5][100][100];

bool ExistWall(int y, int x, int dir, int k){
	int dir_y = 0, dir_x = 0;
	
	bool exist = false;

	switch (dir) {
	case UP:
		dir_y = -1;
		break;
	case DOWN:
		dir_y = 1;
		break;
	case LEFT:
		dir_x = -1;
		break;
	case RIGHT:
		dir_x = 1;
		break;
	}

	int ny = y, nx = x;
	for (int i = 0; i < k; i++) {
		ny += dir_y;
		nx += dir_x;

		if (map[ny][nx]) {
			exist = true;
			break;
		}
	}

	return exist;
}

void BFS() {
	queue<Data> q;
	q.push({ cur_y - 1, cur_x - 1, cur_dir, 0 });
	check[cur_dir][cur_y-1][cur_x-1] = true;

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int dir = q.front().dir;
		int cnt = q.front().cnt;

		q.pop();

		if (y == des_y - 1 && x == des_x - 1 && dir == des_dir) {
			if (ans > cnt) {
				ans = cnt;
				return;
			}
		}

		int n_dir = dir;

		// 왼쪽으로만 회전 
		for (int i = 0; i < 3; i++) {
			switch (n_dir) {
			case UP:
				n_dir = LEFT;
				break;
			case DOWN:
				n_dir = RIGHT;
				break;
			case LEFT:
				n_dir = DOWN;
				break;
			case RIGHT:
				n_dir = UP;
				break;
			}

			if (check[n_dir][y][x])
				continue;

			check[n_dir][y][x] = true;

			if (i == 0 || i == 2) {
				q.push({ y,x,n_dir,cnt + 1 });
			}
			else {
				q.push({ y,x,n_dir,cnt + 2 });
			}
		}

		for (int len = 3; len >= 1; len--) {
			int ny = y, nx = x;
			switch (dir) {
			case UP:
				ny = y - len;
				break;
			case DOWN:
				ny = y + len;
				break;
			case LEFT:
				nx = x - len;
				break;
			case RIGHT:
				nx = x + len;
				break;
			}

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			
			if (map[ny][nx] || check[dir][ny][nx])
				continue;

			if (ExistWall(y, x, dir, len - 1))
				continue;

			check[dir][ny][nx] = true;

			q.push({ ny,nx,dir,cnt + 1 });
		}
	}
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

	cin >> cur_y >> cur_x >> cur_dir;
	cin >> des_y >> des_x >> des_dir;

	BFS();
	
	cout << ans << '\n';

	return 0;
}