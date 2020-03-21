#include <iostream>
#include <vector>

using namespace std; 

int N, K, cnt = 0;
vector<int> coins;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int end;
	
	// 동전의 개수, 목표 값 입력 받기
	cin >> N >> K;

	// N 종류 동전 입력 받기
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		coins.push_back(input);

		// 목표하는 값보다 동전 값어치가 커지기 직전 원소 값 저장
		if (input < K)
			end = i;
	}

	// 마지막부터 순회
	for (int i = end; i >= 0; i--) {
		// 목표하는 값에 도달하면
		if (K == 0) {
			break;
		}

		// 몫으로 cnt 세기
		cnt += K / coins[i];

		// 값어치 조정
		K %= coins[i];
	}
	
	// 정답 출력
	cout << cnt << '\n';
	
	/* 처음 푼 방식
	// 동전의 종류를 마지막부터 순회
	while (true) {
		if (K < coins[end]) {
			// 목표하는 값 보다 값이 크면
			end--;
		}
		else if (K >= coins[end]) {
			// 목표하는 값 보다 값이 작으면
			K -= coins[end];
			cnt++;
		}

		if (K == 0) {
			// 목표하는 값을 다 채웠다면
			break;
		}
	} 

	// 정답 출력
	cout << cnt << '\n';
	*/

	return 0;
}