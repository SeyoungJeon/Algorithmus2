#include <iostream>

using namespace std;

int parent[1000000];
int N, M;

int getParent(int num) {
	if (parent[num] == num)
		return num;
	return parent[num] = getParent(parent[num]);
}

void Union(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool Find(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int op, a, b;
		cin >> op >> a >> b;
		if (op) Find(a, b) ? cout << "YES\n" : cout << "NO\n";
		else Union(a, b);
	}

	return 0;
}