#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int L, C;
vector<char> v, answer;
bool *check;

void DFS(int depth, int cur) {
	if (depth == L-1) {
		int cnt1 = 0;	// ���� ����
		int cnt2 = 0;	// ���� ����

		bool find = false;
		string result = "";

		for (auto k : answer) {
			result += k;
			if (k == 'a' || k == 'e' 
				|| k == 'i' || k == 'o' || k == 'u') {
				// ���� 
				cnt1++;
			}
			else {
				// ����
				cnt2++;
			}
		}

		// ���� 1�� �̻�, ���� 2�� �̻��� ���
		if (cnt1 >= 1 && cnt2 >= 2) {
			find = true;
		}

		// ����� ���
		if (find)
			cout << result << '\n';
		
		return;
	}

	for (int i = cur ; i < v.size(); i++) {
		if (check[i])
			continue;

		// �� Ʈ��ŷ
		check[i] = true;
		answer.push_back(v[i]);
		DFS(depth + 1, i);
		answer.pop_back();
		check[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// ��ȣ ���� , ���ĺ� ���� �Է� �ޱ�
	cin >> L >> C;

	// �湮 ���� ���� �ʱ�ȭ
	check = new bool[C];
	fill_n(check, C, false);

	// ���� �Է� �ޱ�
	for (int i = 0; i < C; i++) {
		char input;
		cin >> input;
		v.push_back(input);
	}

	// ���� �������� ����
	sort(v.begin(), v.end());

	// DFS Ž�� 
	for (int i = 0; i < v.size(); i++) {
		// �� Ʈ��ŷ
		check[i] = true;
		answer.push_back(v[i]);
		DFS(0, i);
		answer.pop_back();
		check[i] = false;
	}
	
	return 0;
}