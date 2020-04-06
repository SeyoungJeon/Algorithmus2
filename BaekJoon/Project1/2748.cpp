#include <iostream>

using namespace std;

long long dp[91], N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// N 입력 받기
	cin >> N;

	// 처음 초기 값
	dp[0] = 0;
	dp[1] = 1;

	// 피보나치 수열 계산
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	// 정답 출력
	cout << dp[N] << '\n';

	return 0;
}