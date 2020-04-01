#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0,pos = 0 ,time = 0 ,cur_weight = 0;
	
	queue<pair<int,int>> q;

	while (true) {
		time++;
		if (q.empty() && pos == truck_weights.size())
			break;

		if (!q.empty() && q.front().second + bridge_length == time) {
			cur_weight -= q.front().first;
			q.pop();
		}

		if (pos == truck_weights.size())
			continue;

		int cur_truck = truck_weights[pos];
		if (cur_weight + cur_truck <= weight) {
			q.push({ cur_truck,time });
			cur_weight += cur_truck;
			pos++;
		}
	}

	answer = time - 1;

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

//	solution(2, 10, { 7,4,5,6 });
	solution(100, 100, { 10 });
	solution(100, 100, { 10,10,10,10,10,10,10,10,10,10 });
	return 0;
}