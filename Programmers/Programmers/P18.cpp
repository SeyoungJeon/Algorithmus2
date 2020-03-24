#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

// 장르, 총 스트리밍 수, 고유번호, 각 스트리밍 수 
map<string, pair<int, vector<pair<int, int>>>> m;

bool compare(const pair<string, pair<int, vector<pair<int,int>>>> &a, const pair<string, pair<int, vector<pair<int, int>>>> &b) {
	if (a.second.first > b.second.first) {
		return true;
	}
	else {
		return false;
	}
}

bool compare2(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.second > b.second) {
		return true;
	}
	else {
		return false;
	}
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	
	for (int i = 0; i < genres.size(); i++) {
		int temp = m[genres[i]].first + plays[i];
		m[genres[i]].first = temp;
		m[genres[i]].second.push_back({ i,plays[i] });
	}

	vector<pair<string, pair<int, vector<pair<int, int>>>>> vec(m.begin(),m.end());

	sort(vec.begin(), vec.end(), compare);

	for (auto k : vec) {
		sort(k.second.second.begin(), k.second.second.end(), compare2);
		for (int i = 0; i < k.second.second.size(); i++) {
			answer.push_back(k.second.second[i].first);
			if (i == 1)
				break;
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<string> genres;
	vector<int> plays;

	genres.push_back("classic");
	genres.push_back("pop");
	genres.push_back("classic");
	genres.push_back("classic");
	genres.push_back("pop");

	plays.push_back(500);
	plays.push_back(600);
	plays.push_back(150);
	plays.push_back(800);
	plays.push_back(2500);

	solution(genres, plays);

	return 0;
}