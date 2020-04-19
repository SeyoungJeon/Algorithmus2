#include <iostream>

using namespace std;

int T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	pair<int, int> *dp;
	dp = new pair<int,int>[41];
	
	dp[0].first = 1; dp[0].second = 0;
	dp[1].first = 0; dp[1].second = 1;

	for (int i = 2; i <= 40; i++) {
		dp[i].first = dp[i - 1].first + dp[i - 2].first;
		dp[i].second = dp[i - 1].second + dp[i - 2].second;
	}

	for (int i = 0; i < T; i++) {
		int input;
		cin >> input;
		
		cout << dp[input].first << ' ' << dp[input].second << '\n';
	}

	return 0;
}