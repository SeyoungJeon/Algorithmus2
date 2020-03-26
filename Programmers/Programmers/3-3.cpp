#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool *check;

int BFS(vector<vector<int>> edge) {
	queue<int> q;
	q.push(1);
	check[1] = true;

	int result = 1;
	while (!q.empty()) {
		int q_size = q.size();
		
		result = q_size;

		for (int i = 0; i < q_size; i++) {
			int node = q.front();
			q.pop();

			for (int j = 0; j < edge[node].size(); j++) {
				int next_node = edge[node][j];

				if (check[next_node])
					continue;
			
				check[next_node] = true;
				q.push(next_node);
			}

		}
	}

	return result;
}
int solution(int n, vector<vector<int>> edge) {
	int answer = 0;

	check = new bool[n + 1];
	fill_n(check, n + 1, false);

	vector<vector<int>> map;
	map.resize(n + 1);

	for (int i = 0; i < edge.size(); i++) {
		map[edge[i][0]].push_back(edge[i][1]);
		map[edge[i][1]].push_back(edge[i][0]);
	}

	answer = BFS(map);

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solution(6, { {3, 6},{4, 3},{3, 2},{1, 3},{1, 2},{2, 4},{5, 2} });
	return 0;
}