#include <iostream>
#include <string>

using namespace std;

string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 식 입력 받기
	cin >> s;

	string num = "";
	bool minus = false, first = false;;
	int result = 0, previous;

	// 식 순회
	for (int i = 0; i < s.size(); i++) {
		
		// 식의 문자가 연산자 일 경우
		if (s[i] == '-') {

			previous = atoi(num.c_str());
			num = "";

			// 처음 숫자일 경우
			if (!first) {
				result = previous;
				first = true;
				minus = true;
				continue;
			}

			// 마이너스 연산자가 안나왔을 경우
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

			// 처음 숫자 일 경우
			if (!first) {
				result = previous;
				first = true;
				continue;
			}

			// 마이너스 연산자가 있었을 경우
			if (minus) {
				result = result - previous;
			}
			else {
				result += previous;
			}
		}
		else {
			// 숫자 일 경우
			num += s[i];
		}
	}

	// 마지막 숫자까지 계산
	if(minus)
		result -= atoi(num.c_str());
	else {
		result += atoi(num.c_str());
	}

	cout << result << '\n';

	return 0;
}