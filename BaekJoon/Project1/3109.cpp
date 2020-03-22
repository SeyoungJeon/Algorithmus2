#include <iostream>
#include <string>

using namespace std;

int R, C, cnt = 0, dir[3][2] = { {-1,1}, {0,1}, {1,1} };
string *map;
bool **check, possible;

void DFS(int row, int col) {
	
	// ������ ��ġ
	check[row][col] = true;

	// ������ ���� �����Ѵٸ�
	if (col == C-1) {
		possible = true;
		return;
	}
	
	// Ž��
	for (int i = 0; i < 3; i++) {
		int ny = row + dir[i][0];
		int nx = col + dir[i][1];

		// ������ ��� ���
		if (ny < 0 || ny >= R || nx < 0 || nx >= C)
			continue;

		// �ǹ��� ���� ���
		if (map[ny][nx] == 'x')
			continue;

		// �̹� �������� ��ġ�� ���̶��
		if (check[ny][nx])
			continue;

		DFS(ny, nx);

		// ������ ��ġ �Ϸ��ߴٸ�
		if (possible)
			return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// �� ����, ���� ���� �Է� �ޱ�
	cin >> R >> C;

	// ��, �湮 ���� �ʱ�ȭ
	map = new string[R];
	check = new bool*[R];
	for (int i = 0; i < R; i++) {
		check[i] = new bool[C];
		fill_n(check[i], C, false);
	}

	// �� ���� �Է� �ޱ�
	for (int i = 0; i < R; i++) {
		cin >> map[i];
	}

	// �࿡ ���� ������ ��ġ�ϱ�
	for (int i = 0; i < R; i++) {
		possible = false;
		DFS(i, 0);

		if (possible)
			cnt++;
	}

	// ���� ���
	cout << cnt << '\n';

	return 0;
}