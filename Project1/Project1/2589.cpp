#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 육지를 저장하는 변수
vector<pair<int, int>> pos;
int a, b, dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
char **map;
bool **check;

void BFS() {
	int max = 0;

	// 육지 순회
	for (auto k : pos) {
		queue<pair<pair<int, int>,int>> q;

		// 시간 변수
		int cnt = 0;

		// 방문 여부 초기화
		for (int i = 0; i < a; i++) {
			fill_n(check[i], b, false);
		}

		// 첫 번째 육지 확인
		q.push({ {k.first,k.second}, cnt });
		check[k.first][k.second] = true;

		while (!q.empty()) {
			int y = q.front().first.first;
			int x = q.front().first.second;
			int cnt = q.front().second;

			q.pop();

			// 현재 저장되어있는 값보다 크면 업데이트
			if (cnt > max)
				max = cnt;

			// 상하좌우 움직이기
			for (int i = 0; i < 4; i++) {
				int ny = y + dir[i][0];
				int nx = x + dir[i][1];

				// 지도 범위 벗어나면 넘기기
				if (ny < 0 || ny >= a || nx < 0 || nx >= b)
					continue;

				// 방문했던 곳은 넘기기
				if (check[ny][nx])
					continue;

				// 바다 넘기기
				if (map[ny][nx] == 'W')
					continue;

				// 다음 방문 할 육지 넣기
				check[ny][nx] = true;
				q.push({ {ny,nx},cnt + 1 });
			}
		}
	}

	// 정답 출력
	cout << max << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 가로 세로 값 받기
	cin >> a >> b;

	// map , 방문 여부 초기화
	map = new char*[a];
	check = new bool*[a];
	for (int i = 0; i < a; i++) {
		map[i] = new char[b];
		check[i] = new bool[b];
	}

	// map 정보 받기
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