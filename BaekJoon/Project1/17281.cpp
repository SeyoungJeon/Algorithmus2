#include <iostream>
#include <vector>

using namespace std;

int N, **map, answer = -1;
bool *visit;
vector<int> order;

int Attack() {
	int inning = 0, outCount = 0, player = 0, attack[4], point = 0;

	while (inning < N) {
		
		outCount = 0;
		fill_n(attack, 4, 0);
		while (outCount < 3) {
			attack[0] = order[player];

			if (map[inning][order[player]] == 0) {
				outCount++;
			}
			else {
				int t = map[inning][order[player]];
				for (int i = 3; i >= 0; i--) {
					if (attack[i] == 0)
						continue;

					if (i + t > 3) {
						point++;
						attack[i] = 0;
					}
					else {
						attack[i + t] = attack[i];
						attack[i] = 0;
					}
				}
			}

			player++;

			if (player == 9)
				player = 0;
		}

		inning++;
	}


	return point;
}

void DFS(int depth) {
	if (depth == 8) {
		auto iter = order.begin() + 3;
		order.insert(iter, 1);

		int an = Attack();
	
		if (answer < an)
			answer = an;

		iter = order.begin() + 3;
		order.erase(iter);
	
		return;
	}

	for (int i = 1; i < 10; i++) {
		int next = i;

		if (visit[next] || i == 1)
			continue;

		visit[next] = true;
		order.push_back(next);
		DFS(depth + 1);
		order.pop_back();
		visit[next] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	map = new int*[N];
	visit = new bool[10];
	fill_n(visit, 10, false);
	for (int i = 0; i < N; i++) {
		map[i] = new int[10];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 1; j < 10; j++) {
			cin >> map[i][j];
		}
	}

	DFS(0);

	cout << answer << '\n';
	
	return 0;
}