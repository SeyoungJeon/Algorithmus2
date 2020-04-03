#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n - lost.size();

	map<int, int> m;

	for (auto k : lost) {
		m[k] = -1;
	}

	for (auto k : reserve) {
		if (m[k] == -1) {
			answer++;
			m[k] = 0;
		}
		else {
			m[k] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (m[i] == 1) {
			if (m[i - 1] == -1) {
				m[i - 1] = m[i] = 0;
				answer++;
				continue;
			}

			if (m[i + 1] == -1) {
				m[i + 1] = m[i] = 0;
				answer++;
				continue;
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 실행 예시 1
	solution(5, { 2,4 }, { 1,3,5 }); // 5
	// 실행 예시 2
	solution(5, { 2,4 }, { 3 }); // 4
	// 실행 예시 3
	solution(3, { 3 }, { 1 }); // 2

	return 0;
}