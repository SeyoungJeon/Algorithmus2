#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

int N ,answer = INT_MAX;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int Fcount = N /5;

	for (int i = Fcount; i >= 0; i--) {
		int remain = N - (5 * i);
		if (remain % 3 == 0) {
			int val = i + (remain / 3);
			if (answer > val)
				answer = val;
		}
	}

	if (answer == INT_MAX)
		answer = -1;

	cout << answer << '\n';

	return 0;
}