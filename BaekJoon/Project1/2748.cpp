#include <iostream>

using namespace std;

long long dp[91], N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// N �Է� �ޱ�
	cin >> N;

	// ó�� �ʱ� ��
	dp[0] = 0;
	dp[1] = 1;

	// �Ǻ���ġ ���� ���
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	// ���� ���
	cout << dp[N] << '\n';

	return 0;
}