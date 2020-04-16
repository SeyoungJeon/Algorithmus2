#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;

	int start = 1;
	for (int i = 0; i < stations.size(); i++) {
		int dif;
		if (i == 0) {
			// 기지국 처음 일 경우
			dif = stations[i] - start - w;
			start = stations[i];
		}
		else {
			// 중간에 있는 애들
			dif = stations[i] - start - 1 - 2 * w;
			start = stations[i];
		}
		
		if (dif < 0)
			continue;

		answer += dif / (2 * w + 1);
		if (dif % (2 * w + 1) != 0)
			answer++;
	}

	int	dif = n - stations[stations.size()-1] - w;
	if (dif > 0) {
		answer += dif / (2 * w + 1);
		if (dif % (2 * w + 1) != 0)
			answer++;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solution(11, { 4,11 }, 1);
	solution(16, { 9 }, 2);

	return 0;
}