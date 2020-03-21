#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string s_num;

// �������� ���Ŀ� �ʿ��� �Լ�
bool compare(const int &a, const int &b) {
	if (a > b) {
		return true;
	}
	else {
		return false;
	}
}

// ���ڿ��� 0�� �����ϰ� �ִ��� �Ǵ��ϴ� �Լ�
bool containtZero(string num) {
	for (int i = 0; i < num.size(); i++) {
		if (num[i] == '0') {
			return true;
		}
	} 

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// ���� �Է� �ޱ�
	cin >> s_num;

	if (!containtZero(s_num)) {
		// ���ڿ��� 0�� �����ϰ� ���� �ʴٸ�
		cout << -1 << '\n';
	}
	else {
		// ���ڿ��� 0�� �����ϰ� �ִٸ�
		bool check = true;
		int total = 0;

		// ���ڿ� ��ȸ
		for (int i = 0; i < s_num.size(); i++) {
			int temp = s_num[i] - '0';

			if (temp == 0 && check) {
				// ���� 0 �� ���� üũ
				check = false;
				continue;
			}
			total += temp;
		}

		// �� ���ڵ��� ���� 3�� ����� �ƴ϶��
		if (total % 3 != 0) {
			cout << -1 << '\n';
			return 0;
		}

		// ���� ������������ ����
		sort(s_num.begin(), s_num.end(),compare);

		cout << s_num << '\n';
	}

	return 0;
}