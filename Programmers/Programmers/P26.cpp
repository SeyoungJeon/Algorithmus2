#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	
	priority_queue<int, vector<int>, less<int>> pq(priorities.begin(), priorities.end());

	deque<pair<int, int>> q;
	for (int i = 0; i < priorities.size(); i++) {
		q.push_back({ i,priorities[i] });
	}

	int count = 0;
	while (!q.empty()) {
		int priority = q.front().second;
		int pos = q.front().first;

		if (pq.top() == priority) {
			count++;
			if (pos == location){
				answer = count;
				break;
			}
			pq.pop();
			q.pop_front();
		}
		else {
			q.pop_front();
			q.push_back({ pos,priority });
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

//	solution({ 2,1,3,2 }, 2);
	solution({ 1,1,9,1,1,1 },0);

	return 0;
}