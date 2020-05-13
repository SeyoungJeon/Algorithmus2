#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> *v;
bool *visit;

int BFS() {
	int result = -1;
	queue<int> q;
	q.push(1);
	visit[1] = true;

	while (!q.empty()) {
		
		size_t size = q.size();
		result += size;
		for (int s = 0; s < size; s++) {
			int cur = q.front();

			q.pop();
			
			for (int i = 0; i < v[cur].size(); i++) {
				int next = v[cur][i];

				if (visit[next])
					continue;

				visit[next] = true;
				q.push(next);
			}
		}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;

	cin >> N >> M;

	v = new vector<int>[N + 1];
	visit = new bool[N + 1];
	fill_n(visit, N + 1, false);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	cout << BFS() << '\n';

	return 0;
}