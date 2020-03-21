#include <iostream>

using namespace std;

int N, cnt = 0;
bool *col, *l, *r;

void DFS(int row) {
	// 모든 행을 순회했을 경우
	if (row == N) {
		cnt++;
		return;
	}

	for (int i = 0; i < N; i++) {
		
		// 열, 왼쪽 대각선, 오른쪽 대각선 가능 여부 판단
		if (col[i] || l[row+i] || r[N-(i-row+1)])
			continue;

		// 백트래킹
		col[i] = l[row + i] = r[N - (i - row + 1)] = true;
		DFS(row + 1);
		col[i] = l[row + i] = r[N - (i - row + 1)] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// N*N 체스판, 퀸의개수 입력 받기
	cin >> N;
	
	// 배열 공간 초기화
	col = new bool[N];
	l = new bool[2*N-1];
	r = new bool[2*N-1];
	fill_n(col, N, false);
	fill_n(l, 2 * N - 1, false);
	fill_n(r, 2 * N - 1, false);

	// 행렬 0부터 탐색
	DFS(0);

	// 정답 출력
	cout << cnt << '\n';

	return 0;
}