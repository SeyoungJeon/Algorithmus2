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

	// ����� ����, ����� ���� ������ ���� �Է� �ޱ�
	cin >> n >> k;

	// Map ���� �ʱ�ȭ
	map = new vector<int>[n + 1];
	
	// ����� ���� ���� �Է� �ޱ�
	for (int i = 0; i < k; i++) {
		int front, back;
		cin >> front >> back;
		map[front].push_back(back);
	}

	// ���ο� Map ���� �ʱ�ȭ
	v = new vector<int>[n + 1];

	// DFS Ž�� �� ����� Visit ���� ���� �ʱ�ȭ
	visit = new bool[n + 1];

	// DFS Ž�� �ϸ� ���� ������
	for (int i = 1; i <= n; i++) {
		fill_n(visit, n + 1, false);
		DFS(0, i, i);
	}

	// ���踦 �˰� ���� ��� ���� ���� �Է� �ޱ�
	cin >> s;

	// �˰� ���� ���� �Է� �ޱ�
	for (int i = 0; i < s; i++) {
		int front, back;
		
		cin >> front >> back;

		bool find = false;

		for (auto k : v[front]) {
			// �տ� ����� ���� �Ͼ�ٸ�
			if (k == back) {
				cout << -1 << '\n';
				find = true;
				break;
			}
		}

		if (find)
			continue;

		for (auto k : v[back]) {
			// �ڿ� ����� ���� �Ͼ�ٸ�
			if (k == front) {
				cout << 1 << '\n';
				find = true;
				break;
			}
		}

		if (find)
			continue;

		// ���踦 ������ �� ���ٸ�
		cout << 0 << '\n';
	}

	return 0;
}