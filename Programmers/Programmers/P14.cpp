#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.second < b.second) {
		return true;
	}
	else {
		return false;
	}
}

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int arr1[5] = { 1,2,3,4,5 };
	int arr2[8] = { 2,1,2,3,2,4,2,5 };
	int arr3[10] = { 3,3,1,1,2,2,4,4,5,5 };

	vector<pair<int, int>> cnt;
	int pos = 0, a[3] = { 0,0,0 }, temp_cnt[3] = { 0,0,0 };

	while (pos < answers.size()) {
		int elem = answers[pos];
		if (arr1[a[0]] == elem) {
			temp_cnt[0]++;
		}

		if (arr2[a[1]] == elem) {
			temp_cnt[1]++;
		}

		if (arr3[a[2]] == elem) {
			temp_cnt[2]++;
		}

		for (int i = 0; i < 3; i++) {
			a[i]++;
		}

		if (a[0] == 5)
			a[0] = 0;

		if (a[1] == 8)
			a[1] = 0;

		if (a[2] == 10)
			a[2] = 0;

		pos++;
	}

	cnt.push_back({ 1,temp_cnt[0] });
	cnt.push_back({ 2,temp_cnt[1] });
	cnt.push_back({ 3,temp_cnt[2] });

	sort(cnt.begin(), cnt.end(), compare);

	answer.push_back(cnt[2].first);
	for (int i = 0; i < 2; i++) {
		if (cnt[2].second == cnt[i].second) {
			answer.push_back(cnt[i].first);
		}
	}

	sort(answer.begin(), answer.end());
	
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solution({ 1,2,3,4,5 });
	return 0;
}