#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	vector<string> temp;
	bool find = false;
	int num, turn;
	string cur = words[0];
	temp.push_back(cur);

	for (int i = 1; i < words.size(); i++) {
		if (cur.at(cur.size() - 1) != words[i].at(0)) {
			find = true;
			temp.push_back(words[i]);
			break;
		}

		for (auto k : temp) {
			if (k == words[i]) {
				temp.push_back(words[i]);
				find = true;
				break;
			}
		}

		if (find)
			break;
		cur = words[i];
		temp.push_back(words[i]);
	}

	if (find) {
		if (temp.size() % n == 0) {
			num = n;
			turn = temp.size() / n;
		}
		else {
			num = (temp.size() % n);
			turn = (temp.size() / n) + 1;
		}
	}
	else {
		num = 0;
		turn = 0;
	}

	answer.push_back(num);
	answer.push_back(turn);

	/*for (auto k : answer) {
		cout << k << ' ';
	}*/

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<string> words;
	
	words.push_back("tank");
	words.push_back("kick");
	words.push_back("know");
	words.push_back("wheel");
	words.push_back("land");
	words.push_back("dream");
	words.push_back("mother");
	words.push_back("robot");
	words.push_back("tank");


	/*words.push_back("hello");
	words.push_back("observe");
	words.push_back("effect");
	words.push_back("take");
	words.push_back("either");
	words.push_back("recognize");
	words.push_back("encourage");
	words.push_back("ensure");
	words.push_back("establish");
	words.push_back("hang");
	words.push_back("gather");
	words.push_back("refer");
	words.push_back("reference");
	words.push_back("estimate");
	words.push_back("executive");*/

	/*words.push_back("hello");
	words.push_back("one");
	words.push_back("even");
	words.push_back("never");
	words.push_back("now");
	words.push_back("world");
	words.push_back("draw");*/
	solution(3, words);
	return 0;
}