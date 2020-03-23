#include <iostream>

using namespace std;

int N, M, K;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 여학생 수, 남학생 수, 인턴쉽에 참여해야하는 인원 입력 받기
	cin >> N >> M >> K;

	int cnt = 0;
	
	// 여학생 수 남학생 수 팀을 이루고 나서도 K 인원보다 이상일 경우 
	// 여학생은 2명이상, 남학생은 1명이상 남아있을 경우
	while (N-2 + M-1 >= K && N >= 2 && M >= 1) {
		N -= 2;
		M -= 1;

		// 팀 개수 세시
		cnt++;
	}

	// 정답 출력
	cout << cnt << '\n';

	return 0;
}