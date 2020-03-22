#include <iostream>
#include <string>

using namespace std;

bool alpha[26] = { false };
int R, C, dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} } , max_val = -1;
char **map;

void DFS(int row, int col, int cnt) {
	// �ִ� �湮 ���� ����
	if (max_val < cnt)
		max_val = cnt;

	// �� Ʈ��ŷ
	for (int i = 0; i < 4; i++) {
		int ny = row + dir[i][0];
		int nx = col + dir[i][1];

		// �� ���� ����� ���
		if (ny < 0 || ny >= R || nx < 0 || nx >= C)
			continue;

		// �̹� �湮�ߴ� ���ĺ� ĭ�� ���
		if (alpha[map[ny][nx] - 'A'])
			continue;

		alpha[map[ny][nx] - 'A'] = true;
		DFS(ny, nx ,cnt + 1);
		alpha[map[ny][nx] - 'A'] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// ���� ����, ���� ���� �Է� �ޱ�
	cin >> R >> C;

	// �� ���� �ʱ�ȭ
	map = new char*[R];
	for (int i = 0; i < R; i++) {
		map[i] = new char[C];
	}

	// ���� ���� �Է� �ޱ�
	for (int i = 0; i < R; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < C; j++) {
			map[i][j] = input[j];
		}
	}

	// �ʱ� ��ġ �湮 Ȯ��
	alpha[map[0][0] - 'A'] = true;

	// BFS Ž��
	DFS(0,0,1);

	// ���� ���
	cout << max_val << '\n';

	return 0;
}