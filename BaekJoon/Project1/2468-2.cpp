#include <iostream>
#include <queue>

using namespace std;

vector<pair<int, int>> safe;
int N, **map, dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} } ,maxSafeArea = 0;
bool **temp, **check;

void SetTempMap(int height) {

	// safe �迭 �ʱ�ȭ
	safe.clear();

	for (int i = 0; i < N; i++) {
		fill_n(check[i], N, false);
		for (int j = 0; j < N; j++) {
			// ���� ���� �����̸� temp �� ����
			if (map[i][j] <= height) {
				temp[i][j] = false;
			}
			else {
				temp[i][j] = true;

				// ��������
				safe.push_back({ i,j });
			}
		}
	}
}

int BFS(pair<int,int> safe) {
	queue<pair<int, int>> q;
	q.push(safe);
	
	check[safe.first][safe.second] = true;
	temp[safe.first][safe.second] = false;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];
			
			// �� ���� �����
			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;

			// ���� ��� �����̶��
			if (!temp[ny][nx])
				continue;

			// �̹� �湮�ߴ� �����̶��
			if (check[ny][nx])
				continue;

			check[ny][nx] = true;
			q.push({ ny,nx });
		}
	}

	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int maxHeight = 0;
	// ������� ���� N �Է� �ޱ�
	cin >> N;

	// map ,temp, check �ʱ�ȭ
	map = new int*[N];
	temp = new bool*[N];
	check = new bool*[N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
		temp[i] = new bool[N];
		check[i] = new bool[N];
	}

	// map ���� �Է� �ޱ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (maxHeight < map[i][j])
				maxHeight = map[i][j];
		}
	}

	// ���̿� ���� �������� ã��
	for (int i = 0; i < maxHeight; i++) {

		int cnt = 0;

		// i ���� ������ �� �� ����
		SetTempMap(i);

		// ���� ���� üũ
		for (auto k : safe) {
			
			// �湮�� �����̰ų� �̹� ���� ��������̶��
			if (check[k.first][k.second] || !temp[k.first][k.second])
				continue;

			cnt += BFS(k);
		}

		if (maxSafeArea < cnt)
			maxSafeArea = cnt;
	}

	for (int i = 0; i < N; i++) {
		delete map[i];
		delete temp[i];
		delete check[i];
	}

	cout << maxSafeArea << '\n';

	return 0;
}