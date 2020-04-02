#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
	int answer = 0;

	sort(weight.begin(), weight.end());


	int total = weight[0];
	for (int i = 1; i < weight.size(); i++) {
		if (weight[i] > total + 1) {
			break;
		}
		total += weight[i];
	}

	answer = total + 1;

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	solution({ 3,1,6,2,7,30,1 });

	return 0;
}