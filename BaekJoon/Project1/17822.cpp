#include <iostream>
#include <set>

using namespace std;

int N, M, T, **map, answer = 0;


void Rotate(int dir, int *arr) {
	int temp = -1;
	switch (dir) {
	case 0:
		// 시계 방향
		temp = arr[M-1];
		for (int i = M-1; i > 0; i--) {
			arr[i] = arr[i - 1];
		}
		arr[0] = temp;

		break;
	case 1:
		//반 시계 방향
		temp = arr[0];
		for (int i = 0; i < M - 1; i++) {
			arr[i] = arr[i + 1];
		}
		arr[M - 1] = temp;
		break;
	}
}

void ChangeValue() {
	int total = 0,cnt = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != -1) {
				total += map[i][j];
				cnt++;
			}
		}
	}

	double avg = (double)total / cnt;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == -1)
				continue;

			if (avg < map[i][j]) {
				map[i][j] -= 1;
			}
			else if (avg > map[i][j]){
				map[i][j] += 1;
			}
		}
	}
}

void ChangeMap() {
	bool check = false;
	set<pair<int, int>> pos;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			int curVal = map[i][j];
			
			if (curVal == -1)
				continue;
			
			bool find = false;

			if (i == 1) {
				// 첫번째 원판일 경우
				if (j == 0) {
					// 양 옆 인접한거 확인
					if (curVal == map[i][M - 1]) {
						find = true;
						pos.insert({ i,M - 1 });
					}
					if (curVal == map[i][j + 1]) {
						find = true;
						pos.insert({ i,j + 1 });
					}
				}
				else if (j == M - 1) {
					// 양 옆 인접한거 확인
					if (curVal == map[i][0]) {
						find = true;
						pos.insert({ i,0 });
					}
					if (curVal == map[i][j - 1]) {
						find = true;
						pos.insert({ i,j - 1 });
					}
				}
				else {
					if (curVal == map[i][j + 1]) {
						find = true;
						pos.insert({ i ,j+1 });
					}

					if (curVal == map[i][j - 1]) {
						find = true;
						pos.insert({ i,j - 1 });
					}
				}

				// 위에 원판확인
				if (curVal == map[i + 1][j]) {
					find = true;
					pos.insert({ i + 1,j });
				}
			}
			else if (i == N) {
				// 마지막 원판일 경우
				if (j == 0) {
					// 양 옆 인접한거 확인
					if (curVal == map[i][M - 1]) {
						find = true;
						pos.insert({ i,M - 1 });
					}
					if (curVal == map[i][j + 1]) {
						find = true;
						pos.insert({ i,j + 1 });
					}
				}
				else if (j == M - 1) {
					// 양 옆 인접한거 확인
					if (curVal == map[i][0]) {
						find = true;
						pos.insert({ i,0 });
					}
					if (curVal == map[i][j - 1]) {
						find = true;
						pos.insert({ i,j - 1 });
					}
				}
				else {
					if (curVal == map[i][j + 1]) {
						find = true;
						pos.insert({ i ,j + 1 });
					}

					if (curVal == map[i][j - 1]) {
						find = true;
						pos.insert({ i,j - 1 });
					}
				}

				// 아래 원판확인
				if (curVal == map[i - 1][j]) {
					find = true;
					pos.insert({ i - 1,j });
				}
				

			}
			else {
				// 중간 원판일 경우
				if (j == 0) {
					// 양 옆 인접한거 확인
					if (curVal == map[i][M - 1]) {
						find = true;
						pos.insert({ i,M - 1 });
					}
					if (curVal == map[i][j + 1]) {
						find = true;
						pos.insert({ i,j + 1 });
					}
				}
				else if (j == M - 1) {
					// 양 옆 인접한거 확인
					if (curVal == map[i][0]) {
						find = true;
						pos.insert({ i,0 });
					}
					if (curVal == map[i][j - 1]) {
						find = true;
						pos.insert({ i,j - 1 });
					}
				}
				else {
					if (curVal == map[i][j + 1]) {
						find = true;
						pos.insert({ i ,j + 1 });
					}

					if (curVal == map[i][j - 1]) {
						find = true;
						pos.insert({ i,j - 1 });
					}
				}

				// 위 아래 원판 확인
				if (curVal == map[i + 1][j]) {
					find = true;
					pos.insert({ i + 1,j });
				}

				if (curVal == map[i - 1][j]) {
					find = true;
					pos.insert({ i - 1,j });
				}
			}

			if (find) {
				check = true;
				pos.insert({ i,j });
			}
		}
	}

	if (check) {
		for (auto s : pos) {
			int y = s.first;
			int x = s.second;
			map[y][x] = -1;
		}
	}
	else {
		ChangeValue();
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> T;

	// 공간 초기화
	map = new int*[N + 1];
	for (int i = 0; i <= N; i++) {
		map[i] = new int[M];
	}

	// 입력 받기
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < T; i++) {
		int x, d, k;
		cin >> x >> d >> k;

		for (int j = 1; j <= N; j++) {
			if (j%x == 0) {
			
				// 회전 
				for (int z = 0; z < k; z++) {
					Rotate(d, map[j]);
				}
			}
		}

		// 검사
		ChangeMap();

	}

	for (int q = 1; q <= N; q++) {
		for (int w = 0; w < M; w++) {
			if (map[q][w] != -1)
				answer += map[q][w];
		}
	}

	cout << answer << '\n';

	return 0;
}