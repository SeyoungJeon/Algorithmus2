#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pos {
	int y;
	int x;
	int height;
};

vector<Pos> v,temp;
int T, N, K, **map, answer, dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
bool **visit, use;

bool compare(const Pos &a, const Pos &b) {
	return a.height > b.height;
}

void DFS(int depth, int row, int col) {
	if (answer < depth)
		answer = depth;

	for (int i = 0; i < 4; i++) {
		int ny = row + dir[i][0];
		int nx = col + dir[i][1];

		// �� ������ ����ٸ�
		if (ny < 0 || ny >= N || nx < 0 || nx >= N)
			continue;

		// �̹� �湮�ߴ� ��ġ���
		if (visit[ny][nx])
			continue;

		// ���� ��ġ���� ������ġ�� �� ���� �����̶��
		if (map[row][col] > map[ny][nx]) {
			visit[ny][nx] = true;
			DFS(depth + 1, ny, nx);
			visit[ny][nx] = false;
		}
		// ���� ��ġ�� ������ġ�� ������ ���ų� ���������̶��
		else {
			// �̹� ���縦 �ߴٸ�
			if (use)
				continue;

			int curVal = map[ny][nx];

			for (int j = 1; j <= K; j++) {
				int nextVal = map[ny][nx] - j;

				// ���� ������ ���̰� ������ ũ�ٸ�
				if (nextVal >= map[row][col])
					continue;

				visit[ny][nx] = true;
				map[ny][nx] = nextVal;
				use = true;
				DFS(depth + 1, ny, nx);
				use = false;
				map[ny][nx] = curVal;
				visit[ny][nx] = false;
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// T �Է� �ޱ�
	cin >> T;

	for (int a = 0; a < T; a++) {
		// N,K �Է� �ޱ�
		cin >> N >> K;

		v.clear();
		answer = -1;
		map = new int*[N];
		visit = new bool*[N];
		for (int i = 0; i < N; i++) {
			map[i] = new int[N];
			visit[i] = new bool[N];
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				v.push_back({ i,j,map[i][j] });
			}
		}

		// ���� ���� �� ����
		sort(v.begin(), v.end(), compare);

		int maxHeight = v[0].height;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].height != maxHeight)
				break;

	
				// �湮 �迭 �ʱ�ȭ
			for (int i = 0; i < N; i++) {
				fill_n(visit[i], N, false);
			}

			visit[v[i].y][v[i].x] = true;
			use = false;
			DFS(0, v[i].y, v[i].x);
		}

		for (int i = 0; i < N; i++) {
			delete[] map[i];
			delete[] visit[i];
		}

		cout << "#" << a+1 << ' ' << answer + 1 << '\n';
	}
	

	return 0;
}