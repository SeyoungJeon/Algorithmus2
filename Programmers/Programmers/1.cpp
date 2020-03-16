#include <iostream>

using namespace std;

long long n, dp[100001];

long long solution(int n) {
	long long answer = 0;

	// �ʱⰪ ����
	dp[0] = 0;
	dp[1] = 1;

	// ��ȸ�ϸ鼭 dp �迭�� ����
	for (int i = 2; i <= n; i++) {
		// �� �� �� ��ü�� �������� ǥ������
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