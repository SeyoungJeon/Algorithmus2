#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D, answer;
bool *visit;

int BFS() {
	bool find = false;
	int time = 0;
	queue<int> q;
	q.push(S);
	visit[S] = 1;

	while (!q.empty()) {
		size_t size = q.size();
		for (int s = 0; s < size; s++) {
			int cur = q.front();
			q.pop();

			if (cur == G){
				find = true;
				break;
			}

			for (int i = 0; i < 2; i++) {
				int next = cur;
				if (i == 0) {
					next += U;
				}
				else {
					next -= D;
				}


				if (next <= 0 || next > F)
					continue;


				if (visit[next])
					continue;

				visit[next] = true;
				q.push(next);
			}
		}

		if (find)
			break;

		time++;
	}

	if (find)
		return time;
	else
		return -1;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> F >> S >> G >> U >> D;
	visit = new bool[F + 1];
	fill_n(visit, F + 1, false);

	answer = BFS();

	if (answer == -1) {
		cout << "use the stairs" << '\n';
	}
	else {
		cout << answer << '\n';
	}

	return 0;
}