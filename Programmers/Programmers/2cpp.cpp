#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> a;

void DFS(int depth,int end, int cur,int n) {
	if (depth >= end) {
		cout << "출력 " << '\n';

		for (auto m : a) {
			cout << m << '\n';
		}
		return;
	}
	for (int i = cur; i < n; i++) {
		a.push_back(i);
		DFS(depth + 1, end, i, n);
		a.pop_back();
	}
}

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	set<string> s;
	for (int i = 0; i < clothes.size(); i++) {
		s.insert(clothes[i][1]);
	}
	
	vector<vector<int>> v(s.size());
	int n = 0;
	for (auto k : s) {
		int cnt = 0;
		for (int i = 0; i < clothes.size(); i++) {
			if (k == clothes[i][1]) {
				cnt++;
			}
		}
		v[n].push_back(cnt);
		n++;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			DFS(0, n, j, n);
		}
	}

	int total = 0;
	for (int i = 0; i < n; i++) {
		answer *= v[i][0];
		total += v[i][0];
	}

	if (n == 1)
		answer = 0;

	answer += total;

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<string>> clothes;
	clothes.resize(3);

	//// 예시 1
	clothes[0].push_back("yellow_hat");
	clothes[0].push_back("headgear");
	clothes[1].push_back("blue_sunglasses");
	clothes[1].push_back("eyewear");
	clothes[2].push_back("green_turban");
	clothes[2].push_back("headgear");
	
	
	// 예시 2
	/*clothes[0].push_back("crow_mask");
	clothes[0].push_back("face");
	clothes[1].push_back("blue_sunglasses");
	clothes[1].push_back("face");
	clothes[2].push_back("smoky_makeup");
	clothes[2].push_back("face");*/
	cout << solution(clothes) << '\n';

	return 0;
}