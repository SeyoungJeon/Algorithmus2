#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>> v[5001];
bool visit[5001];
int N, Q;

int BFS(int k, int m) {
	queue<int> q;
	q.push(m);
	visit[m] = true;

	int count = -1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int val = v[cur][i].second;

			if (visit[next])
				continue;

			if (val < k)
				continue;

			visit[next] = true;
			q.push(next);
		}

		count++;
	}

	return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> Q;

	for (int i = 0; i < N - 1; i++) {
		int p, q, r;
		cin >> p >> q >> r;
		v[p].push_back({ q,r });
		v[q].push_back({ p,r });
	}

	for (int i = 0; i < Q; i++) {
		int k, m;
		cin >> k >> m;
		fill_n(visit, 5001, false);
		cout << BFS(k,m) << '\n';
	}

	return 0;
}