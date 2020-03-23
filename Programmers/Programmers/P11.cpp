#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int answers = 0;
vector<string> s;

bool IsCheck(string target) {
	for (auto k : s) {
		if (k == target) {
			return true;
		}
	} 
	return false;
}

void BFS(string begin, string target, vector<string> words) {
	queue<pair<string, int>> q;
	q.push({ begin , 0 });

	while (!q.empty()) {
		string temp = q.front().first;
		int count = q.front().second;

		q.pop();

		if (temp == target) {
			answers = count;
			return;
		}

		for (int i = 0; i < words.size(); i++) {
			int cnt = 0, pos;
			for (int j = 0; j < words[i].size(); j++) {
				if (temp[j] != words[i][j]) {
					cnt++;
					pos = j;
				}
			}

			if (cnt != 1)
				continue;

			string temp_s = temp;
			temp_s[pos] = words[i][pos];

			int total = 0;
			for (int k = 0; k < temp_s.size(); k++) {
				total += temp_s[k] - 'a';
			}

			if (IsCheck(temp_s))
				continue;

			s.push_back(temp_s);
			q.push({ temp_s, count + 1});
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;

	BFS(begin, target, words);

	cout << answers << '\n';
	return answers;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string begin, target;
	vector<string> words;

	// ¿¹½Ã 1
	begin = "hit";
	target = "cog";

	words.push_back("hot");
	words.push_back("dot");
	words.push_back("dog");
	words.push_back("lot");
	words.push_back("log");
	words.push_back("cog");

	solution(begin, target, words);
	return 0;
}