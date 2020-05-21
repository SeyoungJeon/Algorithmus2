#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int T, N, parent[20001], dist[20001];

int Find(int num) {
	if (parent[num] == num) {
		return num;
	}
	int tmp = Find(parent[num]);
	dist[num] += dist[parent[num]];
	parent[num] = tmp;
	return tmp;
}

void Union(int a, int b) {
	dist[a] = abs(a - b) % 1000;
	parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		char op;
		cin >> N;
		for (int i = 0; i <= N; i++) {
			parent[i] = i;
			dist[i] = 0;
		}

		while (cin >> op, op != 'O') {
			if (op == 'E') {
				int num;
				cin >> num;
				Find(num);
				for (int i = 1; i <= N; i++) {
					cout << parent[i] << ' ';
				}cout << '\n';
//				cout << dist[num] << '\n';
			}
			else {
				int a, b;
				cin >> a >> b;
				Union(a, b);
			}
		}
	}

	return 0;
}