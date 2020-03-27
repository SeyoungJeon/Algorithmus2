#include <iostream>

using namespace std;

int N;
bool **map, **answer, *check;

void DFS(int curNode) {
	for (int i = 0; i < N; i++) {
		int nextNode = i;

		// 다음 노드로 연결이 되있지 않다면
		if (!map[curNode][nextNode])
			continue;

		// 이미 방문했던 노드라면
		if (check[nextNode])
			continue;

		check[nextNode] = true;
		DFS(nextNode);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 정점의 개수 N 입력 받기
	cin >> N;

	// 공간 초기화
	map = new bool*[N];
	answer = new bool*[N];
	check = new bool[N];
	for (int i = 0; i < N; i++) {
		map[i] = new bool[N];
		answer[i] = new bool[N];
		fill_n(answer[i], N, false);
	}

	// 인접 행렬 입력 받기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	// 0번 노드부터 N-1번 노드까지 순회
	for (int i = 0; i < N; i++) {
		fill_n(check, N, false);
		DFS(i);

		// 시작 노드로부터 방문한 노드 표시
		for (int j = 0; j < N; j++) {
			answer[i][j] = check[j];
		}
	}

	// 정답 출력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (answer[i][j]) {
				cout << 1 << ' ';
			}
			else {
				cout << 0 << ' ';
			}
		}
		cout << '\n';
	}


	return 0;
}