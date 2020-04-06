#include <iostream>
#include <map>

using namespace std;

int T, n;
map<int, int> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//// 각 수에 따라 최댓값 구하기
	//for (int i = 1; i <= 100000; i++) {
	//	int temp = i;
	//	int tempAnswer = i;
	//	
	//	bool find = false;

	//	while (temp != 1) {
	//		// 만약 값이 존재한다면 while문 멈추기
	//		if (m[temp] != 0) {
	//			// 존재하는 값과 현재 최댓값을 비교
	//			if (m[temp] > tempAnswer) {
	//				m[i] = m[temp];
	//				find = true;
	//			}
	//			break;
	//		}

	//		if (tempAnswer < temp)
	//			tempAnswer = temp;

	//		if (temp % 2 == 0) {
	//			temp /= 2;
	//		}
	//		else {
	//			temp = temp * 3 + 1;
	//		}
	//	}
	//
	//	if(!find)
	//		m[i] = tempAnswer;
	//
	//}

	// 테스트 케이스 개수 입력 받기
	cin >> T;

	for (int i = 0; i < T; i++) {
		// 수 입력 받기
		cin >> n;

		int answer = n;
		while (n != 1) {
			if (n > answer)
				answer = n;

			if (n % 2 == 0) {
				n /= 2;
			}
			else {
				n = n * 3 + 1;
			}
		}

		cout << answer << '\n';

	}

	return 0;
}