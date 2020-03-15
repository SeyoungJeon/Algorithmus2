#include <iostream>
#include <stack>
#include <string>

using namespace std;

int T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// �׽�Ʈ ���̽� ���� �Է� �ޱ�
	cin >> T;

	// T���� ���ڿ� �Է� �ޱ�
	for (int i = 0; i < T; i++) {
		string input;
		stack<char> st;
		bool balance = true;
		
		// ���ڿ� �Է� �ޱ�
		cin >> input;

		for (int j = 0; j < input.size(); j++) {
			// ���� ��ȣ�� ��� Stack �߰�
			if (input[j] == '(') {
				st.push('(');
			}
			// ���� ��ȣ�� ��� ���� ��ȣ�� ���� ��쿡�� POP
			else {
				// ���� ���� ��ȣ�� ���µ� POP �ؾ� �� ��� ������ �ȸ´´ٰ� �Ǵ�
				if (st.empty()){
					balance = false;
					break;
				}
				st.pop();
			}
		}

		// Stack�� ������� �ʰų� ������ �ȸ´´ٰ� ��
		if (!st.empty() || !balance)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}

	return 0;
}