#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	int idx = 0;
	priority_queue<int, vector<int>, less<int>> pq;

	// 밀가루 양이 k 보다 적은 경우
	while (stock < k) {
		// 밀가루 양이 날짜 보다 크거나 같으면 우선순위 큐에 넣음
		// 자동으로 공급 받을 밀가루 양을 내림차순 정렬 
		for (int i = idx; i < dates.size() && stock >= dates[i] ;i++) {
			pq.push(supplies[i]);
			idx++;
		}

		stock += pq.top();
		pq.pop();
		answer++;
	}

	cout << answer << '\n';

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solution(4, { 4,10,15 }, { 20,5,10 }, 30);
	return 0;
}