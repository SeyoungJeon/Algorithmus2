#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string s_num;

// 내림차순 정렬에 필요한 함수
bool compare(const int &a, const int &b) {
	if (a > b) {
		return true;
	}
	else {
		return false;
	}
}

// 문자열에 0을 포함하고 있는지 판단하는 함수
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

	// 숫자 입력 받기
	cin >> s_num;

	if (!containtZero(s_num)) {
		// 문자열의 0을 포함하고 있지 않다면
		cout << -1 << '\n';
	}
	else {
		// 문자열의 0을 포함하고 있다면
		bool check = true;
		int total = 0;

		// 문자열 순회
		for (int i = 0; i < s_num.size(); i++) {
			int temp = s_num[i] - '0';

			if (temp == 0 && check) {
				// 숫자 0 한 번만 체크
				check = false;
				continue;
			}
			total += temp;
		}

		// 각 숫자들의 합이 3의 배수가 아니라면
		if (total % 3 != 0) {
			cout << -1 << '\n';
			return 0;
		}

		// 숫자 내림차순으로 정렬
		sort(s_num.begin(), s_num.end(),compare);

		cout << s_num << '\n';
	}

	return 0;
}