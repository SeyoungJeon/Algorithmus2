#include <iostream>

using namespace std;

int N;
bool **map, **answer, *check;

void DFS(int curNode) {
	for (int i = 0; i < N; i++) {
		int nextNode = i;

		// ���� ���� ������ ������ �ʴٸ�
		if (!map[curNode][nextNode])
			continue;

		// �̹� �湮�ߴ� �����
		if (check[nextNode])
			continue;

		check[nextNode] = true;
		DFS(nextNode);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// ������ ���� N �Է� �ޱ�
	cin >> N;

	// ���� �ʱ�ȭ
	map = new bool*[N];
	answer = new bool*[N];
	check = new bool[N];
	for (int i = 0; i < N; i++) {
		map[i] = new bool[N];
		answer[i] = new bool[N];
		fill_n(answer[i], N, false);
	}

	// ���� ��� �Է� �ޱ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	// 0�� ������ N-1�� ������ ��ȸ
	for (int i = 0; i < N; i++) {
		fill_n(check, N, false);
		DFS(i);

		// ���� ���κ��� �湮�� ��� ǥ��
		for (int j = 0; j < N; j++) {
			answer[i][j] = check[j];
		}
	}

	// ���� ���
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