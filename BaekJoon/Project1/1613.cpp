#include <iostream>
#include <vector>

using namespace std;

bool *visit;
vector<int> *map,*v;
int n, k, s;

void DFS(int depth, int start, int cur) {

	if (depth != 0)
		v[start].push_back(cur);

	visit[cur] = true;

	for (int i = 0; i < map[cur].size(); i++) {
		int next = map[cur][i];

		if (visit[next])
			continue;

		DFS(depth + 1, start, next);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 사건의 개수, 사건의 전후 관계의 개수 입력 받기
	cin >> n >> k;

	// Map 공간 초기화
	map = new vector<int>[n + 1];
	
	// 사건의 전후 관계 입력 받기
	for (int i = 0; i < k; i++) {
		int front, back;
		cin >> front >> back;
		map[front].push_back(back);
	}

	// 새로운 Map 공간 초기화
	v = new vector<int>[n + 1];

	// DFS 탐색 시 사용할 Visit 변수 공간 초기화
	visit = new bool[n + 1];

	// DFS 탐색 하며 관계 재정리
	for (int i = 1; i <= n; i++) {
		fill_n(visit, n + 1, false);
		DFS(0, i, i);
	}

	// 관계를 알고 싶은 사건 쌍의 개수 입력 받기
	cin >> s;

	// 알고 싶은 관계 입력 받기
	for (int i = 0; i < s; i++) {
		int front, back;
		
		cin >> front >> back;

		bool find = false;

		for (auto k : v[front]) {
			// 앞에 사건이 먼저 일어났다면
			if (k == back) {
				cout << -1 << '\n';
				find = true;
				break;
			}
		}

		if (find)
			continue;

		for (auto k : v[back]) {
			// 뒤에 사건이 먼저 일어났다면
			if (k == front) {
				cout << 1 << '\n';
				find = true;
				break;
			}
		}

		if (find)
			continue;

		// 관계를 유추할 수 없다면
		cout << 0 << '\n';
	}

	return 0;
}