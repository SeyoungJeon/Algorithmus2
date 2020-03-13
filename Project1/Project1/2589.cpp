#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ������ �����ϴ� ����
vector<pair<int, int>> pos;
int a, b, dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
char **map;
bool **check;

void BFS() {
	int max = 0;

	// ���� ��ȸ
	for (auto k : pos) {
		queue<pair<pair<int, int>,int>> q;

		// �ð� ����
		int cnt = 0;

		// �湮 ���� �ʱ�ȭ
		for (int i = 0; i < a; i++) {
			fill_n(check[i], b, false);
		}

		// ù ��° ���� Ȯ��
		q.push({ {k.first,k.second}, cnt });
		check[k.first][k.second] = true;

		while (!q.empty()) {
			int y = q.front().first.first;
			int x = q.front().first.second;
			int cnt = q.front().second;

			q.pop();

			// ���� ����Ǿ��ִ� ������ ũ�� ������Ʈ
			if (cnt > max)
				max = cnt;

			// �����¿� �����̱�
			for (int i = 0; i < 4; i++) {
				int ny = y + dir[i][0];
				int nx = x + dir[i][1];

				// ���� ���� ����� �ѱ��
				if (ny < 0 || ny >= a || nx < 0 || nx >= b)
					continue;

				// �湮�ߴ� ���� �ѱ��
				if (check[ny][nx])
					continue;

				// �ٴ� �ѱ��
				if (map[ny][nx] == 'W')
					continue;

				// ���� �湮 �� ���� �ֱ�
				check[ny][nx] = true;
				q.push({ {ny,nx},cnt + 1 });
			}
		}
	}

	// ���� ���
	cout << max << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// ���� ���� �� �ޱ�
	cin >> a >> b;

	// map , �湮 ���� �ʱ�ȭ
	map = new char*[a];
	check = new bool*[a];
	for (int i = 0; i < a; i++) {
		map[i] = new char[b];
		check[i] = new bool[b];
	}

	// map ���� �ޱ�
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'L')
				pos.push_back({ i,j });
		}
	}
	
	BFS();

	return 0;
}