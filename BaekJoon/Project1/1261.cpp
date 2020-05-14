#include <iostream>
#include <limits.h>
#include <string>
#include <queue>

using namespace std;

struct Pos {
	int y;
	int x;
	int cnt;
};

int N, M, **visit, dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
bool **m;

int BFS() {
	queue<Pos> q;
	q.push({ 1,1,0 });
	visit[1][1] = 0;

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (ny < 1 || ny > N || nx < 1 || nx > M)
				continue;

			// 다음 값을 구해서 더 작은 값을 배열에 저장
			int next = cnt + m[ny][nx];
			if (visit[ny][nx] > next) {
				visit[ny][nx] = next;
				q.push({ ny,nx,cnt + m[ny][nx] });
			}
		}

	}

	return visit[N][M];

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;

	m = new bool*[N + 1];
	visit = new int*[N + 1];
	for (int i = 0; i <= N; i++) {
		m[i] = new bool[M + 1];
		visit[i] = new int[M + 1];
		fill_n(visit[i], M + 1, INT_MAX);
	}

	for (int i = 1; i <= N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < M; j++) {
			m[i][j + 1] = input[j] - '0';
		}
	}

	cout << BFS() << '\n';

	return 0;
}