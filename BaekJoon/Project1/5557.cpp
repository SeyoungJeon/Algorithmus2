#include <iostream>

using namespace std;

long long **dp;
int N, *arr, last;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// N 입력 받기
	cin >> N;

	// dp 배열 초기화
	dp = new long long*[N-1];
	for (int i = 0; i < N-1; i++) {
		dp[i] = new long long[21];
		fill_n(dp[i], 21, 0);
	}

	// 정보 입력 배열 초기화
	arr = new int[N-1];

	// 정보 입력 받기
	for (int i = 0; i < N - 1; i++) {
		cin >> arr[i];
	}

	// 우변 값 입력 받기
	cin >> last;

	// 초기 값 설정
	dp[0][arr[0]] = 1;
	
	// 1부터 N-2 까지 순회
	for (int i = 1; i < N - 1; i++) {
		// 0~20까지 순회
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j] == 0)
				continue;

			if (j + arr[i] <= 20) {
				dp[i][j + arr[i]] += dp[i - 1][j];
			}

			if (j - arr[i] >= 0) {
				dp[i][j - arr[i]] += dp[i - 1][j];
			}
		}
	}

	cout << dp[N - 2][last] << '\n';

	return 0;
}