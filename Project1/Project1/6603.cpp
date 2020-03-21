#include <iostream>
#include <vector>

using namespace std;

int k;

void DFS(int depth, int cur, vector<int> S, bool *check, vector<int> save) {
	// 6개를 선택 완료 했을 경우
	if (depth == 6) {
		// 선택한 로또 출력
		for (auto k : save) {
			cout << k << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = cur; i < S.size(); i++) {
		
		if (check[i])
			continue;

		// 백 트래킹
		check[i] = true;
		save.push_back(S[i]);
		DFS(depth + 1, i, S, check,save);
		save.pop_back();
		check[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 여러개의 테스트 케이스
	while (cin >> k) {
		// k의 값이 0 일 때 종료
		if (k == 0) {
			break;
		}

		// S 집합 변수 선언
		vector<int> s;
		s.resize(k);

		// S 집합 원소 입력 받기
		for (int i = 0; i < k; i++) {
			cin >> s[i];
		}

		// 방문 여부 확인 변수 초기화
		bool *check;
		check = new bool[k];
		fill_n(check, k, false);

		// DFS 탐색
		for (int i = 0; i < s.size(); i++) {
			vector<int> save;
			check[i] = true;
			save.push_back(s[i]);
			DFS(1, i, s, check, save);
			save.pop_back();
			check[i] = false;
		}

		// 메모리 해제
		delete[] check;

		cout << '\n';
	}
	return 0;
}