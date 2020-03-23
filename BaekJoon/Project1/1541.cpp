#include <iostream>
#include <string>

using namespace std;

string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// �� �Է� �ޱ�
	cin >> s;

	string num = "";
	bool minus = false, first = false;;
	int result = 0, previous;

	// �� ��ȸ
	for (int i = 0; i < s.size(); i++) {
		
		// ���� ���ڰ� ������ �� ���
		if (s[i] == '-') {

			previous = atoi(num.c_str());
			num = "";

			// ó�� ������ ���
			if (!first) {
				result = previous;
				first = true;
				minus = true;
				continue;
			}

			// ���̳ʽ� �����ڰ� �ȳ����� ���
			if (!minus) {
				result += previous;
			}
			else {
				result -= previous;
			}

			minus = true;
		}
		else if (s[i] == '+') {
			previous = atoi(num.c_str());
			num = "";

			// ó�� ���� �� ���
			if (!first) {
				result = previous;
				first = true;
				continue;
			}

			// ���̳ʽ� �����ڰ� �־��� ���
			if (minus) {
				result = result - previous;
			}
			else {
				result += previous;
			}
		}
		else {
			// ���� �� ���
			num += s[i];
		}
	}

	// ������ ���ڱ��� ���
	if(minus)
		result -= atoi(num.c_str());
	else {
		result += atoi(num.c_str());
	}

	cout << result << '\n';

	return 0;
}