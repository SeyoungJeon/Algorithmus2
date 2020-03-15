#include <iostream>
#include <stack>

using namespace std;

int N;
stack<pair<int,int>> arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 탑의 개수 입력 받기
	cin >> N;

	// 탑 높이 입력 받기
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		
		// Stack이 비어있지 않다면
		while (!arr.empty()) {

			// 탑이 신호를 수신 가능하다면
			if (arr.top().first > input) {
				cout << arr.top().second + 1 << ' ';
				break;
			}
			arr.pop();
		}
		
		// 수신 가능한 탑이 없다면
		if (arr.empty()) {
			cout << 0 << ' ';
		}

		// 탑의 높이와 위치 추가
		arr.push({ input,i });
	}

	cout << '\n';
	return 0;
}