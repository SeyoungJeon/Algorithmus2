#include <iostream>

using namespace std;

int T, M, N, K, answer , dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
bool **map, **check;

void DFS(int row ,int col) {

	check[row][col] = true;
	
	for (int i = 0; i < 4; i++) {
		int ny = row + dir[i][0];
		int nx = col + dir[i][1];

		// �� �������� ����ٸ�
		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;

		// ���߰� �ɾ��� ���� �ʴٸ�
		if (!map[ny][nx])
			continue;

		// �̹� �湮�ߴ� �ڸ����
		if (check[ny][nx])
			continue;

		DFS(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// �׽�Ʈ ���̽� ���� �Է� �ޱ�
	cin >> T;

	// �׽�Ʈ ���� �ݺ�
	for (int a = 0; a < T; a++) {
		// ����,����, ������ ���� �Է� �ޱ�
		cin >> M >> N >> K;

		// �޸� �Ҵ�
		map = new bool*[N];
		check = new bool*[N];
		for (int i = 0; i < N; i++) {
			map[i] = new bool[M];
			check[i] = new bool[M];
			fill_n(map[i], M, false);
			fill_n(check[i], M, false);
		}

		// ���� �ʱ�ȭ
		answer = 0;

		// ���� ��ġ �Է� �ޱ�
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			map[y][x] = true;
		}

		// ����� ���� �� �迭 ��ȸ
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				// ���߰� ���������� �湮���� �ʾҴ� �ڸ����
				if (map[i][j] && !check[i][j]) {
					DFS(i, j);
					answer++;
				}
			}
		}

		// ���� ���
		cout << answer << '\n';

		// �޸� ���� 
		for (int i = 0; i < N; i++) {
			delete[] map[i];
			delete[] check[i];
		}
	}
	
	return 0;
}