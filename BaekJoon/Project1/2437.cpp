#include <iostream>
#include <algorithm>

using namespace std;

int N,arr[1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 저울추 개수 입력 받기
	cin >> N;

	// 추 원소 입력 받기
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	// 오름 차순 정렬
	sort(arr, arr + N);

	int total = 0;
	for (int i = 0; i < N ; i++) {
		// 누적합 + 1 현재 원소보다 작을 경우
		if (total + 1 < arr[i]) {
			break;
		}

		// 누적합 계산
		total += arr[i];
	}

	// 정답 출력
	cout << total + 1<< '\n';

	return 0;
}
