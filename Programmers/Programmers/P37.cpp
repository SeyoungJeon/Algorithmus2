#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const vector<int> &a, const vector<int> &b) {
	return a.size() < b.size();
}

vector<int> solution(string s) {
	vector<int> answer;

	s = s.substr(1, s.size() - 2);
	
	bool cover = false;

	vector<vector<int>> v;
	vector<int> tempVector;
	string temp = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '{') {
			cover = true;
		}
		else if (s[i] == '}') {
			cover = false;
			tempVector.push_back(stoi(temp));
			temp = "";
			if(i == s.size() -1)
				v.push_back(tempVector);
		}
		else if (s[i] == ',') {
			if (cover) {
				// 괄호가 열려 있을 경우
				tempVector.push_back(stoi(temp));
				temp = "";
			}
			else {
				// 괄호가 닫혀 있을 경우
				v.push_back(tempVector);
				tempVector.clear();
			}
		}
		else {
			// 숫자 일 경우
			temp += s[i];
		}
	}

	sort(v.begin(), v.end(),compare);

	for (int i = 0; i < v.size(); i++) {
		if (!answer.empty()) {
			for (int j = 0; j < answer.size(); j++) {
				for (int k = 0; k < v[i].size(); k++) {
					if (answer[j] == v[i][k]) {
						v[i].erase(v[i].begin() + k);
						break;
					}
				}
			}
		}
		answer.push_back(v[i][0]);
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
	solution("{{1,2,3},{2,1},{1,2,3,4},{2}}");
	solution("{{20,111},{111}}");
	solution("{{123}}");
	solution("{{4,2,3},{3},{2,3,4,1},{2,3}}");
	return 0;
}