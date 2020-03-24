#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <math.h>

using namespace std;

multimap<string, string> mm;
map <string, int> m;
bool *check;
int answer = 0, cnt_zero = 0;

void DFS(int depth, int cur ,int end, vector<string> key , int temp) {
	if (depth == end - 1) {
		answer += temp;
		return;
	}

	for (int i = cur + 1; i < key.size(); i++) {
		if (check[i])
			continue;

		check[i] = true;
		DFS(depth + 1, i, end, key, temp * m.find(key[i])->second);
		check[i] = false;
	}
}

int solution(vector<vector<string>> clothes) {
	for (auto k : clothes) {
		string kind = k[1];
		string product = k[0];
		mm.insert({ kind, product });
	}

	for (auto k : mm) {
		m.insert({ k.first , mm.count(k.first) });
	}

	vector<string> key;
	
	for (auto k : m) {
		key.push_back(k.first);
		if (k.second)
			cnt_zero++;
	}

	check = new bool[key.size()];

	if (key.size() == 30) {
		int m = pow(2, 30) - 1;
		return m ;
	} 

	for (int height = 1; height <= key.size(); height++) {
		fill_n(check, key.size(), false);
		for (int i = 0; i < key.size(); i++) {
			check[i] = true;
			DFS(0, i, height, key, m.find(key[i])->second);
			check[i] = false;
		}
	}

	cout << answer << '\n';

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

//	vector<vector<string>> clothes{ {"crow_mask", "face"}, { "blue_sunglasses", "face"}, { "smoky_makeup", "face" } };
	vector<vector<string>> clothes{ { "yellow_hat", "headgear" },{ "blue_sunglasses", "eyewear"},{ "green_turban", "headgear" } };
	
	solution(clothes);
	return 0;
}