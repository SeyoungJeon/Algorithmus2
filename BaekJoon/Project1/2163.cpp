#include <iostream>

using namespace std;

int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 세로 가로 길이 입력 받기
	cin >> N >> M;

	// 최소 쪼개기 횟수 구하기
	int answer = N * M - 1;

	// 정답 출력
	cout << answer << '\n';

	return 0;
}