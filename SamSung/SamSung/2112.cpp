#include <iostream>
#include <limits.h>

using namespace std;

int T, D, W, K, answer;
bool map[13][20];


bool Check(bool temp[13][20]) {
	for (int j = 0; j < W; j++) {
		bool check = false;
		int count = 1, row = 0;
		bool preVal = temp[row++][j];
		while (row < D) {
			if (preVal == temp[row][j]) {
				count++;
			}
			else {
				preVal = temp[row][j];
				count = 1;
			}

			row++;

			if (count >= K) {
				check = true;
				break;
			}
		}

		if (!check) {
			return false;
		}
	}

	return true;
}

void DFS(int depth,int insert) {
	if (insert >= answer)
		return;

	if (depth >= D) {
		if (Check(map)) {
			answer = answer > insert ? insert : answer;
		}
		return;
	}
	
	// 주입 안하기
	DFS(depth + 1, insert);

	// 임시 공간 
	int t[20];
	for (int i = 0; i < W; i++)
		t[i] = map[depth][i];

	// A,B 주입
	for (int j = 0; j < 2; j++) {
		fill_n(map[depth], W, j);
		DFS(depth + 1, insert + 1);
	}

	// 맵 복원
	for (int i = 0; i < W; i++)
		map[depth][i] = t[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 테스트 케이스 개수 입력받기
	cin >> T;

	for (int test = 1; test <= T; test++) {
		answer = INT_MAX;
		
		cin >> D >> W >> K;

		for (int i = 0; i < D; i++) {
			fill_n(map[i], W, false);
		}

		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}

		DFS(0, 0);
		
		cout << '#' << test << ' ' << answer << '\n';
	}

	return 0;
} 
