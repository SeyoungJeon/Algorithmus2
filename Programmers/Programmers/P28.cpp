#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	answer.resize(prices.size());

	stack<pair<int,int>> s;
	int pos = 0;

	while (pos < prices.size()) {
		if (s.empty()) {
			s.push({ pos,prices[pos] });
			pos++;
		}
		else {
			if (prices[pos] < s.top().second) {
				// 가격이 떨어졌다면
				answer[s.top().first] = pos - s.top().first;
				s.pop();
			}
			else {
				// 가격이 떨어지지 않았다면
				s.push({ pos,prices[pos] });
				pos++;
			}
		}
	}

	while (!s.empty()) {
		answer[s.top().first] = prices.size() - 1 - s.top().first;
		s.pop();
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solution({ 1,2,3,2,3 });

	return 0;
}