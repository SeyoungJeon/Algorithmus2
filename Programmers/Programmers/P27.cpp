#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(string arrangement) {
	int answer = 0;

	deque<int> s;

	for (int i = 0; i < arrangement.size(); i++) {
		if (arrangement[i] == '(') {
			s.push_back(0);
		}
		else {
			int b = s.back();
			if (b == 0) {
				for (int j = 0; j < s.size() - 1; j++) {
					s[j] += 1;
				}
			}
			else {
				answer += (b+1);
			}
			s.pop_back();
		}
	}

	//cout << answer << '\n';

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solution("()(((()())(())()))(())");

	return 0;
}