#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

// 알파벳 배열
int set_val[26] = { 0 };
int N;
vector<string> v;
vector<int> val;

bool compare(const int &a, const int &b) {
	if (a > b)
		return true;
	else
		return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 단어의 개수 입력 받기
	cin >> N;

	// 단어 입력 받기
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		v.push_back(input);
		// 해당 원소에 자릿수 지정
		for (int j = 0; j < input.size(); j++) {
			set_val[input[j] - 'A'] += pow(10, input.size() - j - 1);
		}
	}

	// 값이 존재하는 알파벳 집합 만들기
	for (int i = 0; i < 26; i++) {
		if (set_val[i] != 0) {
			val.push_back(set_val[i]);
		}
	}

	// 자릿값에 대한 내림차순 정렬
	sort(val.begin(), val.end(),compare);

	int total = 0, high = 9;
	// 큰 자리수 부터 큰 수 배정
	for (int i = 0; i < val.size(); i++) {
		total += val[i] * high;
		high--;
	}

	cout << total << '\n';

	return 0;
}