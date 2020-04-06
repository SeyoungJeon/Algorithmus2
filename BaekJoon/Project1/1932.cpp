#include <iostream>

using namespace std;

int **dp, N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// �ﰢ���� ũ�� �Է� �ޱ�
	cin >> N;

	// dp �迭 �ʱ�ȭ
	dp = new int*[N];
	for (int i = 0; i < N; i++) {
		dp[i] = new int[N];
		fill_n(dp[i], N, 0);
	}

	// �ﰢ�� �Է� �ޱ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> dp[i][j];
		}
	}

	// ù ��° ���ҷ� �ʱ�ȭ
	int answer = dp[0][0];

	for (int i = 0; i < N; i++) {
		// �ﰢ�� ù ���� ���
		if (i == 0)
			continue;

		for (int j = 0; j < i + 1; j++) {
			// �ﰢ�� �� ������ ���
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] + dp[i][j];
			}
			// �ﰢ�� �� �������� ���
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + dp[i][j];
			}
			// �ﰢ�� ��� �� ���
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

			// �ִ� ã��
			if (answer < dp[i][j])
				answer = dp[i][j];

		}
	}

	cout << answer << '\n';

	return 0;
}