#include <iostream>

using namespace std;

int **dp, N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 삼각형의 크기 입력 받기
	cin >> N;

	// dp 배열 초기화
	dp = new int*[N];
	for (int i = 0; i < N; i++) {
		dp[i] = new int[N];
		fill_n(dp[i], N, 0);
	}

	// 삼각형 입력 받기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> dp[i][j];
		}
	}

	// 첫 번째 원소로 초기화
	int answer = dp[0][0];

	for (int i = 0; i < N; i++) {
		// 삼각형 첫 줄인 경우
		if (i == 0)
			continue;

		for (int j = 0; j < i + 1; j++) {
			// 삼각형 맨 왼쪽일 경우
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] + dp[i][j];
			}
			// 삼각형 맨 오른쪽일 경우
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + dp[i][j];
			}
			// 삼각형 가운데 일 경우
			else {
				int cur = dp[i][j];
				int prev1 = dp[i - 1][j - 1];
				int prev2 = dp[i - 1][j];

				if (cur + prev1 > cur + prev2) {
					dp[i][j] = cur + prev1;
				}
				else {
					dp[i][j] = cur + prev2;
				}
			}

			// 최댓값 찾기
			if (answer < dp[i][j])
				answer = dp[i][j];

		}
	}

	cout << answer << '\n';

	return 0;
}