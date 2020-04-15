#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

vector<pair<int, int>> *v;
int *value;

int BFS(int K,int N) {
	queue<pair<int, int>> q;
	q.push({ 1,0 });
	
	value[1] = 0;

	while (!q.empty()) {
		size_t size = q.size();
		for (int i = 0; i < size; i++) {
			int node = q.front().first;
			int val = q.front().second;

			q.pop();

			for (int j = 0; j < v[node].size(); j++) {
				int nextNode = v[node][j].first;
				int plus = v[node][j].second;

				if (val + plus > K)
					continue;

				if (value[nextNode] < val + plus)
					continue;

				value[nextNode] = val + plus;
				q.push({ nextNode,val + plus });
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (value[i] <= K)
			cnt++;
	}
	
	return cnt;
}

int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;

	v = new vector<pair<int, int>>[N + 1];
	value = new int[N + 1];
	fill_n(value, N + 1, INT_MAX);

	for (auto k : road) {
		bool find = false;

		int start = k[0];
		int end = k[1];
		int val = k[2];

		v[start].push_back({ end,val });
		v[end].push_back({ start,val });
	}

	answer = BFS(K,N);

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

//	solution(5,{ {1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2} },3);
	solution(6, { {1,2,1},{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1} }, 4);

	return 0;
}