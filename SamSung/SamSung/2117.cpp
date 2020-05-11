#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int CountHome(bool *map[],int y,int x,int N,int K) {
	int cnt = 0;

	for (int i = y - (K - 1); i <= y + (K - 1); i++) {
		// 행 순회
		int dif = abs(i - y);
		int ny = i;

		for (int j = x - (K-dif-1); j < x - (K - dif - 1) + (K - dif) * 2 - 1 ; j++) {
			// 열 순회
			int nx = j;

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;

			if (map[ny][nx])
				cnt++;
		}
	}

	return cnt;
}

int main() {
	int T;

	// 테스트케이스 입력
	cin >> T;

	for (int test = 1; test <= T; test++) {
		int N, M,answer = -1;
		bool ** map;
		
		// N,M 입력 받기
		cin >> N >> M;

		// 맵 정보 공간 할당
		map = new bool*[N];
		for (int i = 0; i < N; i++) {
			map[i] = new bool[N];
			fill_n(map[i], N, false);
		}

		// 맵 정보 입력 받기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		// K 값 순회
		for (int K = 1; K <= 21; K++) {
			int cost = K * K + (K - 1)*(K - 1);

			// 집 순회
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					int countHome = CountHome(map, i, j, N, K);
					int profit = countHome * M - cost;

					// 손해를 보지 않았을 때
					if (profit >= 0) {
						if (answer < countHome) {
							answer = countHome;
						}
					}
				}
			}
		}

		// 맵 공간 해제
		for (int i = 0; i < N; i++) {
			delete[] map[i];
		}
		delete[] map;

		// 정답 출력
		cout << "#" << test << ' ' << answer << '\n';
	}
}