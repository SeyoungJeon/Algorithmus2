#include <iostream>

using namespace std;

long long n, dp[100001];

long long solution(int n) {
	long long answer = 0;

	// 초기값 설정
	dp[0] = 0;
	dp[1] = 1;

	// 순회하면서 dp 배열에 저장
	for (int i = 2; i <= n; i++) {
		// 더 한 값 자체를 나머지로 표현해줌
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
	}

	answer = dp[n];

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	cout << solution(n) << '\n';

	return 0;
}