#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool *check;
vector<int> an;
long long cnt;

void DFS(int depth, int end, vector<int> k,int cur) {
	if (depth == end - 1) {
		if (cnt == 1) {
			an = k;
		}
		cnt--;
		return;
	}

	for (int i = 1; i <= end; i++) {
		int next = i;

		if (check[next])
			continue;

		check[next] = true;
		k.push_back(i);
		DFS(depth + 1, end, k, cur);
		k.pop_back();
		check[next] = false;
	}
	
}

vector<int> solution(int n, long long k) {
	vector<int> answer;
	check = new bool[n+1];
	cnt = k;
	for (int i = 1; i <= n; i++) {
		fill_n(check, n + 1, false);
		check[i] = true;
		vector<int> temp;
		temp.push_back(i);
		DFS(0, n, temp, i);
	}

	return an;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solution(3, 5);
	return 0;
}