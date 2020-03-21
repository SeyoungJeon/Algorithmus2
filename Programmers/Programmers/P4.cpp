#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int cnt = 0;
bool *check;
set<int> m;

bool IsPrime(int input) {
	if (input <= 1) {
		return false;
	}

	for (int i = 2; i < input; i++) {
		if (input % i == 0) {
			return false;
		}
	}

	return true;
}

void DFS(int depth, int end, string numbers, vector<int> s) {
	if (depth >= end) {
		string result = "";
		for (auto k : s) {
			result += to_string(k);
		}

		m.insert(atoi(result.c_str()));

		return;
	}

	for (int i = 0; i < numbers.size(); i++) {
		if (check[i])
			continue;

		check[i] = true;
		s.push_back(numbers[i] - '0');
		DFS(depth + 1, end, numbers, s);
		s.pop_back();
		check[i] = false;
	}
}

int solution(string numbers) {
	int answer = 0;
	check = new bool[numbers.size()];

	for (int i = 0; i < numbers.size(); i++) {
		fill_n(check, numbers.size(), false);
		vector<int> s;
		for (int j = 0; j < numbers.size(); j++) {
			check[j] = true;
			s.push_back(numbers[j] - '0');
			DFS(0, i, numbers, s);
			s.pop_back();
			check[j] = false;
		}
	}

	for (auto k : m) {
		if (IsPrime(k)) {
			cout << k << '\n';
			cnt++;
		}
	}

	answer = cnt;

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << solution("17") << '\n';
	cnt = 0;
	cout << solution("011") << '\n';

	return 0;
}