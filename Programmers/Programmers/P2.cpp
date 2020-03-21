#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int findMinAlphabet(char alphabet) {
	if ('A' <= alphabet && alphabet <= 'N') {
		return alphabet - 'A';
	}
	else {
		return 'Z' - alphabet + 1;
	}
}

int absolute(int a, int b) {
	if (a < b) {
		return b - a;
	}
	else {
		return a - b;
	}
}

int solution(string name) {
	int answer = 0;
	deque<int> pos;

	for (int i = 0; i < name.size(); i++) {
		answer += findMinAlphabet(name[i]);
		if (name[i] != 'A') {
			pos.push_back(i);
		}
	}

	int cur = 0;
	while (!pos.empty()) {
		int front = pos.front();
		int back = pos.back();

		int move_front = absolute(front, cur);
		if (name.size() - move_front < move_front) {
			move_front = name.size() - move_front;
		}
		int move_back = absolute(back,cur);
		if (name.size() - move_back < move_back) {
			move_back = name.size() - move_back;
		}

		if (move_front <= move_back) {
			cur = pos.front();
			pos.pop_front();
			answer += move_front;
		}
		else {
			cur = pos.back();
			pos.pop_back();			
			answer += move_back;
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solution("JEROEN");
	solution("JAN");

	return 0;
}