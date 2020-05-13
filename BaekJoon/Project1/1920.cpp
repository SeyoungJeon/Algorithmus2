#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int N, M;

bool BS(int key) {
	int left = 0, right = N - 1, mid;

	while (left <= right) {
		mid = left + (right - left)/ 2;

		if (v[mid] < key) {
			left = mid + 1;
		}
		else if (v[mid] > key) {
			right = mid - 1;
		}
		else {
			return true;
		}
	}

	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	cin >> M;

	for (int i = 0; i < M; i++) {
		int input;
		cin >> input;
		cout << BS(input) << '\n';
	}

	return 0;
}