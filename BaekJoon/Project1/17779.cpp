#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int N, **A, **temp, answer = INT_MAX;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	A = new int*[N+1];
	temp = new int*[N + 1];
	for (int i = 0; i <= N; i++) {
		A[i] = new int[N+1];
		temp[i] = new int[N + 1];
		fill_n(A[i], N + 1, 0);
		fill_n(temp[i], N + 1, 0);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	for (int d1 = 1; d1 <= N; d1++) {
		for (int d2 = 1; d2 <= N; d2++) {
			for (int x = 1; x <= N; x++) {
				for (int y = 1; y <= N; y++) {

					if (x + d1 + d2 > N)
						continue;

					if (y - d1 < 1 || y + d2 > N)
						continue;

					int arr[6];
					fill_n(arr, 6, 0);

					for (int i = 0; i <= N; i++) {
						fill_n(temp[i], N+1, 0);
					}

					for (int r = 1; r <= N; r++) {
						for (int c = 1; c <= N; c++) {
							if (1 <= r && r < x + d1 && 1 <= c && c <= y) {
								temp[r][c] = 1;
							}
							if (1 <= r <= x + d2 && y < c && c <= N) {
								temp[r][c] = 2;
							}
							if (x + d1 <= r && r <= N && 1 <= c && c < y - d1 + d2) {
								temp[r][c] = 3;
							}
							if (x + d2 < r && r <= N && y - d1 + d2 <= c && c <= N) {
								temp[r][c] = 4;
							}
						}
					}

					// 1번
					for (int i = 0; i <= d1; i++) {
						temp[x + i][y - i] = 5;
					}
					
					// 2번
					for (int i = 0; i <= d2; i++) {
						temp[x + i][y + i] = 5;
					}

					// 3번
					for (int i = 0; i <= d2; i++) {
						temp[x + d1 + i][y - d1 + i] = 5;
					}

					// 4번
					for (int i = 0; i <= d1; i++) {
						temp[x + d2 + i][y + d2 - i] = 5;
					}

					vector<int> v;
					for (int i = 1; i <= N; i++) {
						int count = 0;
						for (int j = 1; j <= N; j++) {
							if (temp[i][j] == 5)
								count++;
						}
						if (count == 2)
							v.push_back(i);
					}

					for (int i = 0; i < v.size(); i++) {
						bool check = false;
						for (int j = 1; j <= N; j++) {
							if (temp[v[i]][j] == 5 && !check)
								check = true;
							else if (temp[v[i]][j] == 5 && check)
								break;
							else if (check)
								temp[v[i]][j] = 5;

						}
					}

					for (int i = 1; i <= N; i++) {
						for (int j = 1; j <= N; j++) {
							switch (temp[i][j]) {
							case 1:
								arr[1] += A[i][j];
								break;
							case 2:
								arr[2] += A[i][j];
								break;
							case 3:
								arr[3] += A[i][j];
								break;
							case 4:
								arr[4] += A[i][j];
								break;
							case 5:
								arr[5] += A[i][j];
								break;
							}
						}
					}

					int max = arr[1], min = arr[1];

					for (int i = 2; i <= 5; i++) {
						if (max < arr[i])
							max = arr[i];

						if (min > arr[i])
							min = arr[i];
					}

					int dif = max - min;

					answer = answer > dif ? dif : answer;
				}
			}
		}
	}

	cout << answer << '\n';

	return 0;
}