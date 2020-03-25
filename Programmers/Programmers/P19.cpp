#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue< int, vector<int>, greater<int> > pq(scoville.begin(), scoville.end());

	bool find = false;
	while (true) {
		if (pq.top() >= K) {
			find = true;
			break;
		}
		if (pq.size() == 1) {
			if (pq.top() >= K)
				find = true;
			
			break;
		}

		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();

		int new_val = first + (second * 2);

		pq.push(new_val);

		answer++;
	}

	if (!find)
		answer = -1;

	//cout << answer << '\n';

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> scoville;
	scoville.push_back(1);
	scoville.push_back(2);
	scoville.push_back(3);
	scoville.push_back(9);
	scoville.push_back(10);
	scoville.push_back(12);

	solution(scoville, 7);

	return 0;
}