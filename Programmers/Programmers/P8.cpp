#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const int &a, const int &b) {
	return a > b;
}

int solution(vector<vector<int>> baseball) {
	int answer = 0;

	vector<int> answers;
	bool arr[1000];
	fill_n(arr, 1000, true);

	for (auto k : baseball) {
		string temp = to_string(k[0]);
		int strike = k[1];
		int ball = k[2];

		for (int q = 1; q < 10; q++) {
			for (int w = 1; w < 10; w++) {
				for (int e = 1; e < 10; e++) {
					if (q == w || w == e || e == q)
						continue;

					string compare = to_string(q) + to_string(w) + to_string(e);

					int strike_cnt = 0;
					int ball_cnt = 0;

					// 스트라이크 카운트
					for (int j = 0; j < 3; j++) {
						if (temp[j] == compare[j])
							strike_cnt++;
					}

					// 볼 카운트
					for (int j = 0; j < 3; j++) {
						for (int k = 0; k < 3; k++) {
							if (j == k)
								continue;

							if (temp[j] == compare[k]) {
								ball_cnt++;
							}
						}
					}

					if (strike != strike_cnt || ball != ball_cnt) {
						arr[stoi(compare)] = false;
					}
				}
			}
		}
		for (int find = 123; find <=987; find++) {
			string compare = to_string(find);
	
		}
	}

	for (int q = 1; q < 10; q++) {
		for (int w = 1; w < 10; w++) {
			for (int e = 1; e < 10; e++) {
				if (q == w || w == e || e == q)
					continue;

				string val = to_string(q) + to_string(w) + to_string(e);

				if (arr[stoi(val)])
					answer++;
			}
		}
	}


	//cout << answer << '\n';

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>> baseball;
	baseball.push_back({ 123,1,1 });
	baseball.push_back({ 356,1,0 });
	baseball.push_back({ 327,2,0 });
	baseball.push_back({ 489,0,1 });

	solution(baseball);

	return 0;
}