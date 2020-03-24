#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

multimap<string,bool> m;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	
	for (auto k : participant) {
		m.insert({ k,false });
	}

	for (auto k : completion) {
		m.erase(m.find(k));
	}

	for (auto k : m) {
		answer = k.first;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<string> participant, completion;

	participant.push_back("mislav");
	participant.push_back("stanko");
	participant.push_back("mislav");
	participant.push_back("ana");
	
	completion.push_back("stanko");
	completion.push_back("ana");
	completion.push_back("mislav");

	solution(participant, completion);

	return 0;
}