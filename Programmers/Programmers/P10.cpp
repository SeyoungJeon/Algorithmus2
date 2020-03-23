#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;

	vector<pair<int, int>> arr;
	int a, b;
	for (int i = 3; i < brown; i++) {
		a = i;
		b = (brown - (i*2)) / 2;
		if (b < 0)
			break;

		if (a >= b + 2 && (a * 2) + (b * 2) == brown) {
			arr.push_back({ a - 2 ,b });
		}
	}

	for (auto k : arr) {
		if (k.first * k.second == red) {
			answer.push_back(k.first + 2);
			answer.push_back(k.second + 2);
			break;
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solution(24, 24);
	return 0;
}