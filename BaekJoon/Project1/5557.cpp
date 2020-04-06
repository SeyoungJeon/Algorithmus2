#include <iostream>

using namespace std;

long long **dp;
int N, *arr, last;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// N �Է� �ޱ�
	cin >> N;

	// dp �迭 �ʱ�ȭ
	dp = new long long*[N-1];
	for (int i = 0; i < N-1; i++) {
		dp[i] = new long long[21];
		fill_n(dp[i], 21, 0);
	}

	// ���� �Է� �迭 �ʱ�ȭ
	arr = new int[N-1];

	// ���� �Է� �ޱ�
	for (int i = 0; i < N - 1; i++) {
		cin >> arr[i];
	}

	// �캯 �� �Է� �ޱ�
	cin >> last;

	// �ʱ� �� ����
	dp[0][arr[0]] = 1;
	
	// 1���� N-2 ���� ��ȸ
	for (int i = 1; i < N - 1; i++) {
		// 0~20���� ��ȸ
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