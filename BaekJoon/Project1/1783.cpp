#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 가로 세로 입력 받기
	cin >> N >> M;

	int cnt = 1;
	
	/* 높이에 따라 단계를 나눠주는게 중요 ! */

	if (N == 2) {
		// 높이가 2라면
		cnt = min(4, (M+1) / 2);
	}
	else if (N >= 3) {
		// 높이가 3 이상이라면
		if (M < 7) {
			// 모든 이동방법을 사용할 수 없는 경우
			cnt = min(4, M);
		}
		else {
			// 모든 이동방법을 사용할 수 있는 경우
			cnt = M - 2;
		}
	}
	cout << cnt << '\n';

	return 0;
}