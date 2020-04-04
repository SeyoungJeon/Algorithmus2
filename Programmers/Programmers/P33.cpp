#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool *visit, possible;
vector<int> *map, *v;
int *arr; 

void DFS(int cur,int depth, int n, int start) {
	visit[cur] = true;

	if(depth != 0){
		arr[cur]++;
		v[start].push_back(cur);
	}

	for (int i = 0; i < map[cur].size(); i++) {
		int next = map[cur][i];

		if (visit[next])
			continue;

		DFS(next,depth+1,n,start);
	}
}

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	map = new vector<int>[n + 1];
	v = new vector<int>[n + 1];
	visit = new bool[n + 1];
	arr = new int[n + 1];
	fill_n(arr, n + 1, 0);

	for (int i = 0; i < results.size(); i++) {
		int winner = results[i][0];
		int loser = results[i][1];
		map[winner].push_back(loser);
	}

	for (int i = 1; i <= n; i++) {
		fill_n(visit, n + 1, false);
		DFS(i, 0, n,i);
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] + v[i].size() == n - 1)
			answer++;
	}
	
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solution(5, { {4,3},{4,2},{3,2},{1,2},{2,5} });

	return 0;
}