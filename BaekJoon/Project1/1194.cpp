// ��Ʈ����ũ
#include <iostream>
#include <queue>

using namespace std;

struct Pos {
	int y;
	int x;
	int k;
};

int N, M, sy, sx, dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
char map[50][50];
int visit[50][50][64];

int BFS() {
	queue<Pos> q;

	q.push({ sy,sx,0 });

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int k = q.front().k;

		q.pop();

		if (map[y][x] == '1') {
			return visit[y][x][k];
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];
			int nk = k;
		
			// ��ġ�� ����ų� ���� ���
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || map[ny][nx] == '#')
				continue;

			// �̹� �湮�ߴ� �����
			if (visit[ny][nx][nk])
				continue;
			
			// ���踦 �߰����� ���
			if ('a' <= map[ny][nx] && map[ny][nx] <= 'f') {
				nk |= (1 << (map[ny][nx] - 'a'));	 // Shift �������� ���� ǥ��
			}
			// ���� �߰����� ���
			else if ('A' <= map[ny][nx] && map[ny][nx] <= 'F') {
				if (!(nk & (1 << (map[ny][nx] - 'A'))))	// Shift ���� �� ���谡 �����Ѵٸ�
					continue;
			}

			q.push({ ny,nx,nk });

			// DP ó�� ���� ��ġ�� �ϳ��� �ø��� 
			visit[ny][nx][nk] = visit[y][x][k] + 1;
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	// �� ���� �Է� �ޱ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == '0') {
				sy = i; sx = j;
			}
		}
	}
	
	cout << BFS() << '\n';

	return 0;
}