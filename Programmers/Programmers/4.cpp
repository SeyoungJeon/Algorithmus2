#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &a, const string &b) {
	if (a.size() != b.size()) {
		if (a.at(0) > b.at(0) && a.size() < b.size()) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (a > b) {
			return true;
		}
		else {
			return false;
		}
	}
}

string solution(vector<int> numbers) {
	string answer = "";

	vector<string> s_num;
	for (int i = 0; i < numbers.size(); i++) {
		s_num.push_back(to_string(numbers[i]));
	}

	sort(s_num.begin(), s_num.end(), compare);

	for (int i = 0; i < s_num.size(); i++) {
		answer += s_num[i];
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> numbers;

	// 실행 예시1
	/*numbers.push_back(6);
	numbers.push_back(10);
	numbers.push_back(2);*/

	//// 실행 예시 2
	numbers.push_back(3);
	numbers.push_back(30);
	numbers.push_back(34);
	numbers.push_back(5);
	numbers.push_back(9);

	cout << solution(numbers) << '\n';

	return 0;
}