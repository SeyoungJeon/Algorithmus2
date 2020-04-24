#include <iostream>
#include <stack>
#include <deque>

#define R 1
#define L 2
#define U 3
#define D 4

using namespace std;

struct Pos {
	int y;
	int x;
	int dir;
};

Pos *pos;
int N, K,**map,answer ;
stack<int> **s;

void GO_WHITE(deque<int> temp,int curY,int curX, int curDir, int cur) {
	while (!temp.empty()) {
		int m = temp.front();
		int mDir = pos[m].dir;
		pos[m] = { curY,curX,mDir };
		temp.pop_front();
		s[curY][curX].push(m);
	}
	pos[cur].dir = curDir;
}

void GO_RED(deque<int> temp, int curY, int curX, int curDir, int cur) {
	while (!temp.empty()) {
		int m = temp.back();
		int mDir = pos[m].dir;
		pos[m] = { curY,curX,mDir };
		temp.pop_back();
		s[curY][curX].push(m);
	}
	pos[cur].dir = curDir;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// N�� K �Է� �ޱ�
	cin >> N >> K;

	// map ���� �ʱ�ȭ
	map = new int*[N+1];
	for (int i = 0; i <= N; i++) {
		map[i] = new int[N+1];
	}

	// stack ���� �ʱ�ȭ�ϱ�
	s = new stack<int>*[N + 1];
	for (int i = 0; i <= N; i++) {
		s[i] = new stack<int>[N + 1];
	}

	// �� ��� �Է� �ޱ�
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	// �� ���� �ʱ�ȭ �ϱ�
	pos = new Pos[K+1];
	for (int i = 1; i <= K; i++) {
		int r, c, d;
		cin >> r >> c >> d;
		s[r][c].push(i);
		pos[i] = { r,c,d };
	}

	int turn = 1;
	while (turn <= 1000) {
		bool find = false;

		// ���� ���� ��ġ�� ���� 4�� �̻� ������ ���� ���
		for (int i = 1; i <= K; i++) {
			deque<int> temp;
			int curY = pos[i].y;
			int curX = pos[i].x;
			int curDir = pos[i].dir;

			while (!s[curY][curX].empty()) {
				int t = s[curY][curX].top();
				s[curY][curX].pop();
				temp.push_front(t);

				if (i == t)
					break;
			}

			switch (curDir) {
			case U:
				curY--;
				break;
			case R:
				curX++;
				break;
			case D:
				curY++;
				break;
			case L:
				curX--;
				break;
			}

			// �� ������ ����ų� �Ķ��� ĭ���� �̵��Ϸ��� �� ���
			if (curY < 1 || curY > N || curX < 1 || curX > N
				|| map[curY][curX] == 2) {
				curY = pos[i].y;
				curX = pos[i].x;

				switch (curDir) {
				case U:
					curDir = D;
					curY++;
					break;
				case R:
					curDir = L;
					curX--;
					break;
				case D:
					curDir = U;
					curY--;
					break;
				case L:
					curDir = R;
					curX++;
					break;
				 }

				if (curY < 1 || curY > N || curX < 1 || curX > N
					|| map[curY][curX] == 2) {
					curY = pos[i].y;
					curX = pos[i].x;
					// �̵��� ĭ�� �� �� ������ ����ų� �Ķ����� ��� ���⸸ �ٲٰ� ������ �ֱ�
					while (!temp.empty()) {
						int m = temp.front();
						temp.pop_front();
						s[curY][curX].push(m);
					}
					pos[i].dir = curDir;
				}
				else if (map[curY][curX] == 0) {
					// ������ �ϴ� ���� ����� ���
					GO_WHITE(temp, curY, curX, curDir, i);
				}
				else if (map[curY][curX] == 1) {
					// ������ �ϴ� ���� �������� ���
					GO_RED(temp, curY, curX, curDir, i);
				}
			}
			else if (map[curY][curX] == 1) {
				// ������ �ϴ� ���� �������� ���
				GO_RED(temp, curY, curX, curDir, i);
			}
			else if (map[curY][curX] == 0) {
				// ������ �ϴ� ���� ����� ���
				GO_WHITE(temp, curY, curX, curDir, i);
			}

			// �ش� ��ġ�� ���� 4�� �̻� �׿��� ���
			if (s[curY][curX].size() >= 4) {
				find = true;
				break;
			}
		}

		if (find) {
			answer = turn;
			break;
		}

		turn++;
	}

	if (turn > 1000)
		answer = -1;

	cout << answer << '\n';

	return 0;
}