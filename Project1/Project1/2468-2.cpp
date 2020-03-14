#include <iostream>
#include <queue>

using namespace std;

vector<pair<int, int>> safe;
int N, **map, dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} } ,maxSafeArea = 0;
bool **temp, **check;

void SetTempMap(int height) {

	// safe 배열 초기화
	safe.clear();

	for (int i = 0; i < N; i++) {
		fill_n(check[i], N, false);
		for (int j = 0; j < N; j++) {
			// 물의 높이 이하이면 temp 맵 설정
			if (map[i][j] <= height) {
				temp[i][j] = false;
			}
			else {
				temp[i][j] = true;

				// 안전지역
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
			
			// 맵 범위 벗어나면
			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;

			// 물에 잠긴 지역이라면
			if (!temp[ny][nx])
				continue;

			// 이미 방문했던 지역이라면
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
	// 행과열의 개수 N 입력 받기
	cin >> N;

	// map ,temp, check 초기화
	map = new int*[N];
	temp = new bool*[N];
	check = new bool*[N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
		temp[i] = new bool[N];
		check[i] = new bool[N];
	}

	// map 정보 입력 받기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (maxHeight < map[i][j])
				maxHeight = map[i][j];
		}
	}

	// 높이에 따라 안전지역 찾기
	for (int i = 0; i < maxHeight; i++) {

		int cnt = 0;

		// i 높이 이하일 때 맵 설정
		SetTempMap(i);

		// 안전 지역 체크
		for (auto k : safe) {
			
			// 방문한 지역이거나 이미 물에 잠긴지역이라면
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