#include <iostream>
#include <queue>

using namespace std;

int N, K, d[2] = { 1,-1 };
bool visit[100001] = { false };

int BFS() {
	int time = 0;
	queue<int> q;
	q.push(N);
	visit[N] = 1;

	while (!q.empty()) {

		size_t size = q.size();
		bool find = false;
		for (int s = 0; s < size; s++ ) {
			int cur = q.front();
			q.pop();

			if (cur == K) {
				find = true;
				break;
			}

			if (cur * 2 <= 100000 && visit[cur * 2] == 0) {
				visit[cur * 2] = 1;
				q.push(cur * 2);
			}

			for (int i = 0; i < 2; i++) {
				int next = cur + d[i];

				if (next < 0 || next > 100000)
					continue;

				if (visit[next])
					continue;

				visit[next] = 1;
				q.push(next);
			}
		}

		if (find)
			break;

		time++;
	}

	return time;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	cout << BFS() << '\n';

	return 0;
}