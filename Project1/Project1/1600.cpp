#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dir[8][2] = { {-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-2,1},{-1,2} };
int dir2[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int K, W, H, ans;
bool **map, ***visit;
queue<pair<pair<int,int>,pair<int, int>>> q;

bool Check_Border(int y, int x) {
	if (y < 0 || y >= H || x < 0 || x >= W)
		return false;
	else
		return true;
}

int BFS() {
//	int result = 0;

	q.push({ {0,0},{0,0} });

	visit[0][0][0] = true;

	while (!q.empty()) {

		int cnt = q.front().first.first;
		int knight = q.front().first.second;
		int cur_y = q.front().second.first;
		int cur_x = q.front().second.second;

		q.pop();

		if (cur_y == H - 1 && cur_x == W - 1)
			return cnt;

		if (knight < K) {
			// 富贸烦 青悼且 版快 
			for (int j = 0; j < 8; j++) {
				int ny = cur_y + dir[j][0];
				int nx = cur_x + dir[j][1];

				if (!Check_Border(ny, nx) || visit[ny][nx][knight + 1] || map[ny][nx])
					continue;

				visit[ny][nx][knight + 1] = true;

				q.push({ { cnt + 1,knight + 1 }, { ny, nx } });
			}
		}
		
		for (int j = 0; j < 4; j++) {
			int ny = cur_y + dir2[j][0];
			int nx = cur_x + dir2[j][1];

			if (!Check_Border(ny, nx) || visit[ny][nx][knight] || map[ny][nx])
				continue;

			visit[ny][nx][knight] = true;
			q.push({ {cnt + 1,knight},{ ny,nx } });
		}
		
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> K;
	cin >> W >> H;

	map = new bool*[H];
	visit = new bool**[H];
	for (int i = 0; i < H; i++) {
		map[i] = new bool[W];
		visit[i] = new bool*[W];
		fill_n(map[i], W, false);
		for (int j = 0; j < W; j++) {
			visit[i][j] = new bool[32];
			fill_n(visit[i][j], 32, false);
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}

	ans = BFS();

	cout << ans << '\n';

	for (int i = 0; i < H; i++) {
		delete[] map[i];
		for (int j = 0; j < W; j++) {
			delete[] visit[i][j];
		}
	}

	return 0;
}