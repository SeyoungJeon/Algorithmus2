#include <iostream>

using namespace std;

int T, M, N, K, answer , dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
bool **map, **check;

void DFS(int row ,int col) {

	check[row][col] = true;
	
	for (int i = 0; i < 4; i++) {
		int ny = row + dir[i][0];
		int nx = col + dir[i][1];

		// 맵 범위에서 벗어난다면
		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;

		// 배추가 심어져 있지 않다면
		if (!map[ny][nx])
			continue;

		// 이미 방문했던 자리라면
		if (check[ny][nx])
			continue;

		DFS(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 테스트 케이스 개수 입력 받기
	cin >> T;

	// 테스트 개수 반복
	for (int a = 0; a < T; a++) {
		// 가로,세로, 배추의 개수 입력 받기
		cin >> M >> N >> K;

		// 메모리 할당
		map = new bool*[N];
		check = new bool*[N];
		for (int i = 0; i < N; i++) {
			map[i] = new bool[M];
			check[i] = new bool[M];
			fill_n(map[i], M, false);
			fill_n(check[i], M, false);
		}

		// 정답 초기화
		answer = 0;

		// 배추 위치 입력 받기
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			map[y][x] = true;
		}

		// 유기농 배추 맵 배열 순회
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				// 배추가 존재하지만 방문하지 않았던 자리라면
				if (map[i][j] && !check[i][j]) {
					DFS(i, j);
					answer++;
				}
			}
		}

		// 정답 출력
		cout << answer << '\n';

		// 메모리 해제 
		for (int i = 0; i < N; i++) {
			delete[] map[i];
			delete[] check[i];
		}
	}
	
	return 0;
}