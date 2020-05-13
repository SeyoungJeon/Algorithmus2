#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		pq.push(input);
	}

	while (!pq.empty()) {
		cout << pq.top() << '\n';
		pq.pop();
	}

	return 0;
}