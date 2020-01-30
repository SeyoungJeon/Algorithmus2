#include <iostream>

using namespace std;

int map[10][10];
int color[5] = { 5,5,5,5,5 };
int ans = 101,result;

void func(int row, int col) {

	// 1~10 열 모두 확인했으면 다음 행으로
	if (col == 10) {
		func(row+1, 0);
		return;
	}

	// 마지막 행까지 모두 확인했으면
	if (row == 10) {

		// 최소되는 값 저장
		if (result < ans) {
			ans = result;
		}
		return;
	}

	// 종이를 덮을 필요가 없는 칸
	if (map[row][col] == 0) {
		func(row, col + 1);
		return;
	}

	// 종이 1~5칸 커버
	for (int i = 1; i <= 5; i++) {

		// 색종이 5개 남았는지, 범위 넘어갔는지 
		if (color[i - 1] == 0 || row + i > 10 || col + i > 10)
			continue;

		bool possible = true;
		for (int k = 0; k < i; k++) {
			for (int l = 0; l < i; l++) {
				if (map[row+k][col+l] == 0){
					possible = false;
					break;
				}
			}
			if (!possible)
				break;
		}

		if (!possible)
			continue;

		for (int k = 0; k < i; k++) {
			for (int l = 0; l < i; l++) {
				map[row + k][col + l] = 0;
			}
		}

		color[i - 1]--;
		result++;
		
		func(row, col + i);

		for (int k = 0; k < i; k++) {
			for (int l = 0; l < i; l++) {
				map[row + k][col + l] = 1;
			}
		}

		color[i - 1]++;
		result--;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
		}
	}

	func(0, 0);

	if (ans == 101) {
		cout << -1 << '\n';
	}
	else {
		cout << ans << '\n';
	}
	return 0;
}