#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> budgets, int M) {
	int answer = 0;
	int max_val = -1;
	long long total = 0;

	for (auto k : budgets) {
		total += k;
		if (k > max_val)
			max_val = k;
	}
	
	if (total > M) {
		priority_queue<int, vector<int>, greater<int>> pq(budgets.begin(), budgets.end());
		
		int average = M / budgets.size();
		int size = budgets.size();
		int count = 0;
		bool find = false;
		while (!pq.empty()) {

			if (pq.top() <= average) {
				M -= pq.top();
				pq.pop();
				count++;
				find = false;
			}
			else {
				average = M / (size - count);
				size -= count;
				count = 0;
				
				if (find)
					break;
				
				find = true;
			}
		}

		answer = average;

		cout << answer << '\n';
	}
	else {
		// 요청한 것이 M 보다 작다면
		answer = max_val;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solution({ 120,110,140,150 }, 485);

	return 0;
}