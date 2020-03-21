#include <iostream>

using namespace std;

int C, N, *grade;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// C++ 출력 형식 설정
	cout << fixed;
	cout.precision(3);

	// 테스트 케이스 개수 입력 받기
	cin >> C;

	// 테스트 케이스 입력 받기
	for (int i = 0; i < C; i++) {
		float avg = 0;
		int studentCnt = 0, total = 0;
		// 학생 수 입력 받기
		cin >> N;

		// 학생들의 점수 배열 초기화
		grade = new int[N];
		
		// 학생들의 점수 입력 받기
		for (int j = 0; j < N; j++) {
			cin >> grade[j];
			total += grade[j];
		}

		// 평균 계산
		avg = total / N;

		for (int j = 0; j < N; j++) {
			// 평균 넘은 학생 세기
			if (avg < grade[j])
				studentCnt++;
		}

		// 평균 넘은 학생 비율 출력
		// C언어
//		printf("%0.3f%%\n", ((double)studentCnt / (double)N) * 100);
			
		cout << ((float)studentCnt / (float)N) * 100 << "%\n";
	}

	return 0;
}