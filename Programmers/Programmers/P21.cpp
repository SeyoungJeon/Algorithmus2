#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct cmp {
	bool operator()(vector<int> a, vector<int> b) {
		return a.at(1) > b.at(1);
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0, count = 0, time = 0;

	// jobs 이중 배열 정렬
	sort(jobs.begin(), jobs.end());

	priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

	while (count < jobs.size() || !pq.empty()) {
		// 작업 요청이 들어와 있다면
		if (count < jobs.size() && time >= jobs[count][0]) {
			pq.push(jobs[count++]);
			continue;
		}

		// 현재 작업 중인 것이 있다면
		if (!pq.empty()) {
			time += pq.top()[1];
			answer += time - pq.top()[0];
			pq.pop();
		}
		// 현재 작업 중인 것이 없다면
		else {
			time = jobs[count][0];
		}
	}

	return answer/count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solution({ {0, 3}, {0,1},{1,5}, { 1, 9}, { 2, 6} });
	
	return 0;
}