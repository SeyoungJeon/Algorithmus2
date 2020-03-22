#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

// ���ĺ� �迭
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

	// �ܾ��� ���� �Է� �ޱ�
	cin >> N;

	// �ܾ� �Է� �ޱ�
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		v.push_back(input);
		// �ش� ���ҿ� �ڸ��� ����
		for (int j = 0; j < input.size(); j++) {
			set_val[input[j] - 'A'] += pow(10, input.size() - j - 1);
		}
	}

	// ���� �����ϴ� ���ĺ� ���� �����
	for (int i = 0; i < 26; i++) {
		if (set_val[i] != 0) {
			val.push_back(set_val[i]);
		}
	}

	// �ڸ����� ���� �������� ����
	sort(val.begin(), val.end(),compare);

	int total = 0, high = 9;
	// ū �ڸ��� ���� ū �� ����
	for (int i = 0; i < val.size(); i++) {
		total += val[i] * high;
		high--;
	}

	cout << total << '\n';

	return 0;
}