#include <iostream>
#include <queue>

using namespace std;

struct Pos {
	int z;
	int y;
	int x;
};

queue<Pos> q;
int M, N, H, ***map, dir[6][3] = { {-1,0,0},{1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1} };

int BFS() {
	int time = -1;
	
	while (!q.empty()) {
		size_t size = q.size();
		for (int s = 0; s < size; s++) {
			int z = q.front().z;
			int y = q.front().y;
			int x = q.front().x;

			q.pop();

			for (int i = 0; i < 6; i++) {
				int nz = z + dir[i][0];
				int ny = y + dir[i][1];
				int nx = x + dir[i][2];

				if (nz < 0 || nz >= H || ny < 0 || ny >= N || nx < 0 || nx >= M)
					continue;

				if (map[nz][ny][nx] == 1 || map[nz][ny][nx] == -1)
					continue;

				map[nz][ny][nx] = 1;
				q.push({ nz,ny,nx });
			}
		}
		time++;
	}

	bool check = true;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (map[i][j][k] == 0)
				{
					check = false;
					break;
				}
			}
			if (!check)
				break;
		}
		if (!check)
			break;
	}

	if (!check)
		return -1;
	else
		return time;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N >> H;

	map = new int**[H];
	for (int i = 0; i < H; i++) {
		map[i] = new int*[N];
		for (int j = 0; j < N; j++) {
			map[i][j] = new int[M];
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1) {
					q.push({ i,j,k });
				}
			}
		}
	}

	cout << BFS() << '\n';
	
	return 0;
}