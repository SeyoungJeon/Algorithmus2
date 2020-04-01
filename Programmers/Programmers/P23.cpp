#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<pair<int,int>> t;

vector<int> solution(vector<int> heights) {
	vector<int> answer;

	for (int i = 0; i < heights.size(); i++) {
		while (!t.empty()) {
			if (t.top().first > heights[i]){
				answer.push_back(t.top().second);
				break;
			}
			t.pop();
		}

		if (t.empty()) {
			answer.push_back(0);
		}

		t.push({ heights[i],i + 1 });
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solution({ 6,9,5,7,4 });

	return 0;
}