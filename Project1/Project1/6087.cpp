#include <iostream>
#include <queue>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

using namespace std;

struct Data {
	int y;
	int x;
	int dir;
	int cnt;
};

int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1 } };
int W, H;
char map[100][100];
int visit[100][100];
int s_y = -1, s_x, d_y, d_x;

void BFS() {
	queue<Data> q;
	for (int i = 0; i < 4; i++) {
		q.push({ s_y,s_x,i,0 });
	}

	visit[s_y][s_x] = 0;

	while (!q.empty()) {
		int cur_y = q.front().y;
		int cur_x = q.front().x;
		int cur_dir = q.front().dir;
		int cur_cnt = q.front().cnt;

		q.pop();

		cout << cur_y << ' ' << cur_x << '\n';
		for (int i = 0; i < 4; i++) {
			int ny = cur_y + dir[i][0];
			int nx = cur_x + dir[i][1];
			int n_cnt = cur_cnt;
			
			if (ny < 0 || ny >= H || nx < 0 || nx >= W)
				continue;

			if (map[ny][nx] == '*')
				continue;

			if (cur_dir != i) {
				n_cnt = n_cnt + 1;
			}

			if (visit[ny][nx] >= n_cnt) {
				visit[ny][nx] = n_cnt;
				q.push({ ny,nx,i,cur_cnt });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> W >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'C') {
				if (s_y == -1) {
					s_y = i;
					s_x = j;
				}
				else {
					d_y = i;
					d_x = j;
				}
			}
			visit[i][j] = 987654321;
		}
	}

	BFS();

	cout << visit[d_y][d_x] << '\n';
	return 0;
}