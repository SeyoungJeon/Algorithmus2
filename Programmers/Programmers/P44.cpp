#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<string> *v,temp;
set<set<string>> k;
int answer = 0;


void DFS(int depth,int end) {
	if (depth == end) {
		set<string> s(temp.begin(), temp.end());
		if(s.size() == end)
			k.insert(s);
		return;
	}

	for (int i = 0; i < v[depth].size(); i++) {
		temp.push_back(v[depth][i]);
		DFS(depth + 1, end);
		temp.pop_back();
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	v = new vector<string>[banned_id.size()];
	
	for (int i = 0; i < banned_id.size(); i++) {
		string ban = banned_id[i];
		for (int j = 0; j < user_id.size(); j++) {
			string user = user_id[j];

			if (ban.size() != user.size())
				continue;

			bool check = true;
			for (int k = 0; k < user.size(); k++) {
				if (ban[k] != user[k] && ban[k] != '*')
				{
					check = false;
					break;
				}
			}

			if (check) {
				v[i].push_back(user);
			}
		}
	}

	DFS(0, banned_id.size());

	answer = k.size();
	
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "fr*d*", "abc1**" });
	solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "*rodo", "*rodo", "******" });
	//solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "fr*d*", "*rodo", "******", "******" });

	return 0;
}