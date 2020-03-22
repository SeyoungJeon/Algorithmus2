#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const string &a, const string &b) {
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	string answer = "";

	vector<string> s;
	for (auto k : numbers) {
		s.push_back(to_string(k));
	}

	sort(s.begin(), s.end(), compare);

	if (s.at(0) == "0")
		return "0";

	for (auto k : s) {
		answer += k;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> numbers;

	// 예시1
	//numbers.push_back(6);
	//numbers.push_back(10);
	//numbers.push_back(2);

	// 예시2 
	numbers.push_back(3);
	numbers.push_back(30);
	numbers.push_back(34);
	numbers.push_back(5);
	numbers.push_back(9);



	solution(numbers);
	return 0;
}