#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int L, C;
vector<char> v, answer;
bool *check;

void DFS(int depth, int cur) {
	if (depth == L-1) {
		int cnt1 = 0;	// 모음 개수
		int cnt2 = 0;	// 자음 개수

		bool find = false;
		string result = "";

		for (auto k : answer) {
			result += k;
			if (k == 'a' || k == 'e' 
				|| k == 'i' || k == 'o' || k == 'u') {
				// 모음 
				cnt1++;
			}
			else {
				// 자음
				cnt2++;
			}
		}

		// 모음 1개 이상, 자음 2개 이상일 경우
		if (cnt1 >= 1 && cnt2 >= 2) {
			find = true;
		}

		// 결과값 출력
		if (find)
			cout << result << '\n';
		
		return;
	}

	for (int i = cur ; i < v.size(); i++) {
		if (check[i])
			continue;

		// 백 트래킹
		check[i] = true;
		answer.push_back(v[i]);
		DFS(depth + 1, i);
		answer.pop_back();
		check[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 암호 길이 , 알파벳 개수 입력 받기
	cin >> L >> C;

	// 방문 여부 공간 초기화
	check = new bool[C];
	fill_n(check, C, false);

	// 문자 입력 받기
	for (int i = 0; i < C; i++) {
		char input;
		cin >> input;
		v.push_back(input);
	}

	// 문자 오름차순 정렬
	sort(v.begin(), v.end());

	// DFS 탐색 
	for (int i = 0; i < v.size(); i++) {
		// 백 트래킹
		check[i] = true;
		answer.push_back(v[i]);
		DFS(0, i);
		answer.pop_back();
		check[i] = false;
	}
	
	return 0;
}