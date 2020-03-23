#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cnt = 0;

void DFS(int depth,int end ,vector<int> numbers,int sum , int target) {
	if (depth == end) {
		if (sum == target) {
			cnt++;
		}
		return;
	}

	DFS(depth + 1, end, numbers, sum + numbers[depth], target);
	DFS(depth + 1, end, numbers, sum - numbers[depth], target);
}

int solution(vector<int> numbers, int target) {
	int answer = 0;

	DFS(0, numbers.size() ,numbers, 0, target);

	answer = cnt;

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> s;

	s.push_back(1);
	s.push_back(1);
	s.push_back(1);
	s.push_back(1);
	s.push_back(1);

	solution(s, 3);

	return 0;
}