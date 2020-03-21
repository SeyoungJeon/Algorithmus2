#include <iostream>
#include <vector>

using namespace std;

int k;

void DFS(int depth, int cur, vector<int> S, bool *check, vector<int> save) {
	// 6���� ���� �Ϸ� ���� ���
	if (depth == 6) {
		// ������ �ζ� ���
		for (auto k : save) {
			cout << k << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = cur; i < S.size(); i++) {
		
		if (check[i])
			continue;

		// �� Ʈ��ŷ
		check[i] = true;
		save.push_back(S[i]);
		DFS(depth + 1, i, S, check,save);
		save.pop_back();
		check[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// �������� �׽�Ʈ ���̽�
	while (cin >> k) {
		// k�� ���� 0 �� �� ����
		if (k == 0) {
			break;
		}

		// S ���� ���� ����
		vector<int> s;
		s.resize(k);

		// S ���� ���� �Է� �ޱ�
		for (int i = 0; i < k; i++) {
			cin >> s[i];
		}

		// �湮 ���� Ȯ�� ���� �ʱ�ȭ
		bool *check;
		check = new bool[k];
		fill_n(check, k, false);

		// DFS Ž��
		for (int i = 0; i < s.size(); i++) {
			vector<int> save;
			check[i] = true;
			save.push_back(s[i]);
			DFS(1, i, s, check, save);
			save.pop_back();
			check[i] = false;
		}

		// �޸� ����
		delete[] check;

		cout << '\n';
	}
	return 0;
}