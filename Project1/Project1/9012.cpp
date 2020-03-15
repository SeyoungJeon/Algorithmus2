#include <iostream>
#include <stack>
#include <string>

using namespace std;

int T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 테스트 케이스 개수 입력 받기
	cin >> T;

	// T개의 문자열 입력 받기
	for (int i = 0; i < T; i++) {
		string input;
		stack<char> st;
		bool balance = true;
		
		// 문자열 입력 받기
		cin >> input;

		for (int j = 0; j < input.size(); j++) {
			// 열린 괄호일 경우 Stack 추가
			if (input[j] == '(') {
				st.push('(');
			}
			// 닫힌 괄호일 경우 열린 괄호가 있을 경우에만 POP
			else {
				// 만약 열린 괄호가 없는데 POP 해야 할 경우 균형이 안맞는다고 판단
				if (st.empty()){
					balance = false;
					break;
				}
				st.pop();
			}
		}

		// Stack이 비어있지 않거나 균형이 안맞는다고 판
		if (!st.empty() || !balance)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}

	return 0;
}