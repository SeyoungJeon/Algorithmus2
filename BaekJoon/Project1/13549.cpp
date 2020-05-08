#include <iostream>
#include <queue>

using namespace std;

int N, K, answer;
bool visit[100001] = { false };

int BFS() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int result = -1;
	pq.push({ 0,N });
	visit[N] = true;
	
	while (!pq.empty()) {
		int cnt = pq.top().first;
		int val = pq.top().second;

		pq.pop();

		if (val == K) {
			result = cnt;
			break;
		}

		if (val * 2 <= 100000 && !visit[val * 2]) {
			pq.push({ cnt,val * 2 });
			visit[val * 2] = true;
		}

		if (val + 1 <= 100000 && !visit[val + 1]) {
			pq.push({ cnt + 1,val + 1 });
			visit[val + 1] = true;
		}

		if (val - 1 >= 0 && !visit[val - 1]) {
			pq.push({ cnt + 1,val - 1 });
			visit[val - 1] = true;
		}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	cout << BFS() << '\n';

	return 0;
}