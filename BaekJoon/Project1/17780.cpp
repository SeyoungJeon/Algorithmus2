#include <iostream>
#include <deque>
#include <stack>

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

Pos p[11];
int N, K, color_map[13][13], answer, d[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
int cd[4] = { 2,1,4,3 };
stack<int> map[13][13];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> color_map[i][j];
		}
	}

	for (int i = 1; i <= K; i++) {
		int y, x, dir;
		cin >> y >> x >> dir;
		p[i] = { y,x,dir };
		map[y][x].push(i);
	}

	bool find = false;
	for (int time = 1; time <= 1000; time++) {
		for (int m = 1; m <= K; m++) {
			int y = p[m].y;
			int x = p[m].x;
			int dir = p[m].dir;

			deque<int> temp;
			
			// �ӽ÷� �� ��ȣ ������ �ֱ�
			while (!map[y][x].empty()) {
				temp.push_back(map[y][x].top());
				map[y][x].pop();
			}

			if (temp.back() == m) {
				// �� �Ʒ��� �ִ� ���� ���� ���
				int ny = y + d[dir-1][0];
				int nx = x + d[dir-1][1];
				int nd = dir;

				if (ny < 1 || ny > N || nx < 1 || nx > N ||
					color_map[ny][nx] == 2) {
					// �� ������ ����ų� ���� �Ķ����� ���
					nd = cd[dir - 1];
					ny = y + d[nd - 1][0], nx = x + d[nd - 1][1];
				}
				
				// �� �Ķ����̰ų� �� �迭�� ����� ���
				if (ny < 1 || ny > N || nx < 1 || nx > N ||
					color_map[ny][nx] == 2) {
					p[m].dir = nd;
					while (!temp.empty()) {
						map[y][x].push(temp.back());
						temp.pop_back();
					}
				}
				else if (color_map[ny][nx] == 1) {
					// ������ �� ���
					while (!temp.empty()) {
						int s = temp.front();
						map[ny][nx].push(s);
						p[s].y = ny, p[s].x = nx;
						if (s == m) {		// �ش� ���� ���� ��ȭ
							p[s].dir = nd;
						}
						temp.pop_front();
					}
				}
				else if (color_map[ny][nx] == 0) {
					// ����� ���
					while (!temp.empty()) {
						int s = temp.back();
						map[ny][nx].push(s);
						p[s].y = ny, p[s].x = nx;
						if (s == m) {	// �ش� ���� ���� ��ȭ
							p[s].dir = nd;
						}
						temp.pop_back();
					}
				} 

			}
			else {
				// �� �ַ��� �ִ� ���� �ƴ� ��� �ٽ� stack�� �ױ�
				while (!temp.empty()) {
					map[y][x].push(temp.back());
					temp.pop_back();
				}
			}

			// �ش� ��ġ�� 4�� ���δٸ�
			if (map[p[m].y][p[m].x].size() >= 4)
			{
				find = true;
				break;
			}
		}

		if (find) {
			cout << time << '\n';
			break;
		}
	}

	if (!find)
		cout << -1 << '\n';

	return 0;
}


