#include <iostream>
#include <vector>

using namespace std;

int N, M, parent[201];
vector<pair<int,int>> edge;
vector<int> plan;

int getParent(int num) {
	if (parent[num] == num) {
		return num;
	}

	return parent[num] = getParent(parent[num]);
}

void Union(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

bool Find(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a == b)
		return true;

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	cin >> M;

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int input;
			cin >> input;
			if(input == 1 && j > i)
				edge.push_back({ i + 1,j + 1 });
		}
	}

	for (int i = 0; i < M; i++) {
		int input;
		cin >> input;
		plan.push_back(input);
	}

	for (auto k : edge) {
		Union(k.first, k.second);
	}

	bool possible = true;
	for (int i = 1; i < plan.size(); i++) {
		if (!Find(plan[0], plan[i])) {
			possible = false;
			break;
		}
	}

	if (possible)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';

	return 0;
}