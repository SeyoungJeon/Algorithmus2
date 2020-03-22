#include <iostream>
#include <string>

using namespace std;

int R, C, cnt = 0, dir[3][2] = { {-1,1}, {0,1}, {1,1} };
string *map;
bool **check, possible;

void DFS(int row, int col) {
	
	// 파이프 설치
	check[row][col] = true;

	// 오른쪽 열에 도달한다면
	if (col == C-1) {
		possible = true;
		return;
	}
	
	// 탐색
	for (int i = 0; i < 3; i++) {
		int ny = row + dir[i][0];
		int nx = col + dir[i][1];

		// 범위를 벗어날 경우
		if (ny < 0 || ny >= R || nx < 0 || nx >= C)
			continue;

		// 건물이 있을 경우
		if (map[ny][nx] == 'x')
			continue;

		// 이미 파이프가 설치된 곳이라면
		if (check[ny][nx])
			continue;

		DFS(ny, nx);

		// 파이프 설치 완료했다면
		if (possible)
			return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 맵 가로, 세로 길이 입력 받기
	cin >> R >> C;

	// 맵, 방문 여부 초기화
	map = new string[R];
	check = new bool*[R];
	for (int i = 0; i < R; i++) {
		check[i] = new bool[C];
		fill_n(check[i], C, false);
	}

	// 맵 정보 입력 받기
	for (int i = 0; i < R; i++) {
		cin >> map[i];
	}

	// 행에 따라 파이프 설치하기
	for (int i = 0; i < R; i++) {
		possible = false;
		DFS(i, 0);

		if (possible)
			cnt++;
	}

	// 정답 출력
	cout << cnt << '\n';

	return 0;
}