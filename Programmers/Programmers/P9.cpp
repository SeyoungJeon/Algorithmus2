#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool *check;

void DFS(int cur_node, vector<vector<int>> computers) {
	
	check[cur_node] = true;

	for (int i = 0 ; i < computers[cur_node].size(); i++) {
		if (check[i] )
			continue;

		if (computers[cur_node][i] == 0)
			continue;

		DFS(i, computers);
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	check = new bool[n];
	fill_n(check, n, false);

	for (int i = 0; i < n; i++) {
		if (check[i])
			continue;

		DFS(i, computers);
		answer++;
	}

	cout << answer << '\n';

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>> computers;
	computers.push_back({ 1,1,0 });
	computers.push_back({ 1,1,0 });
	computers.push_back({ 0,0,1 });

	solution(3, computers);

	return 0;
}