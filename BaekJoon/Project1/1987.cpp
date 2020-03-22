#include <iostream>
#include <string>

using namespace std;

bool alpha[26] = { false };
int R, C, dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} } , max_val = -1;
char **map;

void DFS(int row, int col, int cnt) {
	// 최대 방문 개수 저장
	if (max_val < cnt)
		max_val = cnt;

	// 백 트래킹
	for (int i = 0; i < 4; i++) {
		int ny = row + dir[i][0];
		int nx = col + dir[i][1];

		// 맵 범위 벗어났을 경우
		if (ny < 0 || ny >= R || nx < 0 || nx >= C)
			continue;

		// 이미 방문했던 알파벳 칸일 경우
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

	// 보드 가로, 세로 길이 입력 받기
	cin >> R >> C;

	// 맵 공간 초기화
	map = new char*[R];
	for (int i = 0; i < R; i++) {
		map[i] = new char[C];
	}

	// 보드 정보 입력 받기
	for (int i = 0; i < R; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < C; j++) {
			map[i][j] = input[j];
		}
	}

	// 초기 위치 방문 확인
	alpha[map[0][0] - 'A'] = true;

	// BFS 탐색
	DFS(0,0,1);

	// 정답 출력
	cout << max_val << '\n';

	return 0;
}