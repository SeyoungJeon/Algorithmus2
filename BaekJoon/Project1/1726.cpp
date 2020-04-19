#include <iostream>
#include <queue>
#include <limits.h>

#define E 1
#define W 2
#define S 3
#define N 4

using namespace std;

struct Pos {
	int y;
	int x;
	int dir;
	int cnt;
};

int R, C, s_r, s_c, s_d, d_r, d_c, d_d , answer = INT_MAX;
bool **map, ***visit;


int TurnLeft(int curDir) {
	switch (curDir) {
	case N:
		curDir = W;
		break;
	case E:
		curDir = N;
		break;
	case S:
		curDir = E;
		break;
	case W:
		curDir = S;
		break;
	}

	return curDir;
}

int TurnRight(int curDir) {
	switch (curDir) {
	case N:
		curDir = E;
		break;
	case E:
		curDir = S;
		break;
	case S:
		curDir = W;
		break;
	case W:
		curDir = N;
		break;
	}

	return curDir;
}

void BFS() {
	queue<Pos> q;
	q.push({ s_r,s_c,s_d,0 });
	visit[s_r][s_c][s_d] = true;

	while (!q.empty()) {
		int curY = q.front().y;
		int curX = q.front().x;
		int curDir = q.front().dir;
		int curCnt = q.front().cnt;

		q.pop();

		// ���������� ���
		if (curY == d_r && curX == d_c && curDir == d_d) {
			if (answer > curCnt)
				answer = curCnt;

			return;
		}

		int right = TurnRight(curDir), left = TurnLeft(curDir);

		// ������ ȸ��
		if (!visit[curY][curX][right]){
			visit[curY][curX][right] = true;
			q.push({ curY,curX,right,curCnt + 1 });
		}

		// ���� ȸ��
		if (!visit[curY][curX][left]){
			visit[curY][curX][left] = true;
			q.push({ curY,curX,left,curCnt + 1 });
		}

		// 3 ~ 1 ���⿡ ���� ����
		for (int go = 3; go >= 1; go--) {
			int ny = curY, nx = curX;

			bool possible = true;

			for (int i = 1; i <= go; i++) {
				switch (curDir) {
				case N:
					ny -= 1;
					break;
				case E:
					nx += 1;
					break;
				case S:
					ny += 1;
					break;
				case W:
					nx -= 1;
					break;
				}

				// �� ���� ����� ���
				if (ny < 1 || ny > R || nx < 1 || nx > C) {
					possible = false;
					break;
				}

				// ������ ���� �������� ���
				if (map[ny][nx]) {
					possible = false;
					break;
				}
			}

			if (!possible)
				continue;
			
			// �̹� �湮�ߴ� ��ġ���
			if (visit[ny][nx][curDir])
				continue;

			visit[ny][nx][curDir] = true;
			q.push({ ny,nx,curDir,curCnt + 1 });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// �� ���� ���� �Է� �ޱ�
	cin >> R >> C;

	// 2���� �� �迭, 3���� �湮 �迭 �ʱ�ȭ
	map = new bool*[R + 1];
	visit = new bool**[R + 1];
	for (int i = 0; i <= R; i++) {
		map[i] = new bool[C + 1];
		fill_n(map[i], C + 1, false);
		visit[i] = new bool*[C + 1];
		for (int j = 0; j <= C; j++) {
			visit[i][j] = new bool[5];
			fill_n(visit[i][j], 5, false);
		}
	}
	
	// �� �迭 �Է� �ޱ�
	for (int i = 1;  i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
		}
	}
	
	// �������, �������� �Է� �ޱ�
	cin >> s_r >> s_c >> s_d;
	cin >> d_r >> d_c >> d_d;

	// Ž��
	BFS();

	// ���� ���
	cout << answer << '\n';

	return 0;
}