#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>

using namespace std;

long long N,answer;
int M;
vector<long long> arr;

long long BS() {
	// 최대 크기 2000000000 * 30 설정
	long long left = 1, right = 60000000000, mid,sum;
	long long result = -1;
	while (left <= right) {
		mid = (left + right) / 2;
		
		// 해당 시간에 탔던 사람들 구하기
		sum = M;
		for (int i = 1; i <= M; i++) {
			sum += (mid / arr[i]);
		}

		// 탔던 사람보다 N이 작거나 같으면
		if (sum >= N) {
			result = mid;	// 시간 저장
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// N,M 입력 받기
	cin >> N >> M;

	// M 배열 크기 할당
	arr.resize(M + 1);

	// 배열 원소 입력 받기
	for (int i = 1; i <= M; i++) {
		cin >> arr[i];
	}
	
	// 사람보다 놀이기구 수가 많을 경우
	if (N <= M) {
		cout << N << '\n';
		return 0;
	}

	// 이진탐색
	long long time = BS();
	long long sum = M;

	// 이전 시간까지 탔던 사람 구하기
	for (int i = 1; i <= M; i++) {
		sum += (time - 1) / arr[i];
	}

	// 해당 시간에 몇번째로 타는지 구하기
	for (int i = 1; i <= M; i++) {
		if (time % arr[i] == 0) {
			sum++;
		}

		if (sum == N) {
			cout << i << '\n';
			break;
		}
	}

	return 0;
}