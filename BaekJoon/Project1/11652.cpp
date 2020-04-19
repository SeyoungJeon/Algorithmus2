#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<long long, int> m;
int N;

bool compare(const pair<long long, int> &a, const pair<long long, int> &b) {
	if (a.second == b.second)
		return a.first < b.first;

	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		long long input;
		cin >> input;

		int curVal = m[input];
		m[input] = curVal + 1;
	}

	vector<pair<long long, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), compare);

	cout << v[0].first << '\n';

	return 0;
}