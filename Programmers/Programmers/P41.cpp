#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
	int answer = 0;
	
	deque<int> tempA(A.begin(),A.end()), tempB(B.begin(),B.end());

	sort(tempA.begin(), tempA.end());
	sort(tempB.begin(), tempB.end());
	
	while (!tempB.empty()) {
		int a = tempA.front();
		int b = tempB.front();
		
		if (a < b) {
			tempA.pop_front();
			tempB.pop_front();
			answer++;
		}
		else {
			tempB.pop_front();
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solution({ 5,1,3,7 }, { 2,2,6,8 });
	solution({ 2,2,2,2 }, { 1,1,1,1 });

	return 0;
}