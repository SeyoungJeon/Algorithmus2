#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	deque<int> q(progresses.begin(), progresses.end());
	deque<int> s(speeds.begin(), speeds.end());
	
	while (true) {
		for (int i = 0; i < q.size(); i++) {
			q[i] += s[i];
		}

		int total = 0;
		while (!q.empty() && q.front() >= 100) {
			q.pop_front();
			s.pop_front();
			total++;
		}

		if(total !=0)
			answer.push_back(total);

		if (q.empty())
			break;
	}

	return answer;
}

int main() {
	solution({ 93,30,55 }, { 1,30,5 });
	return 0;
}