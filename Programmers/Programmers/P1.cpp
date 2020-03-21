#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	
	list<string> q;

	if (cacheSize == 0) {
		answer += cities.size() * 5;
		return answer;
	}

	for (auto k : cities) {
		string str = k;
		for (int i = 0; i < str.size(); i++) {
			str[i] = tolower(str[i]);
		}

		bool find = false;
		for (auto m : q) {
			if (str == m) {
				q.remove(m);
				find = true;
				break;
			}
		}

		if (!find) {
			// miss
			if (q.size() == cacheSize) {
				q.pop_back();
			}
			q.push_front(str);
			answer += 5;
		}
		else {
			// hit
			answer += 1;
			q.push_front(str);
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<string> cities;

	cities.push_back("Jeju");
	cities.push_back("Pangyo");
	cities.push_back("Seoul");
	cities.push_back("NewYork");
	cities.push_back("LA");
	cities.push_back("Jeju");
	cities.push_back("Pangyo");
	cities.push_back("Seoul");
	cities.push_back("NewYork");
	cities.push_back("LA");

	cout << solution(3,cities) << '\n';

	return 0;
}