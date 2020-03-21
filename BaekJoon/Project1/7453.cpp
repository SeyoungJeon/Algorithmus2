#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long N, arr[4][4000];
vector<long long> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 배열의 길이 입력 받기
	cin >> N;

	// 각 배열의 요소 입력 받기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[j][i];
		}
	}

	// 3번째 4번째 배열 합치기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			v.push_back(arr[2][i] + arr[3][j]);
		}
	}

	// 3번쨰, 4번째 배열 합친 것 오름차순 정렬하기
	sort(v.begin(), v.end());

	long long result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// 1번째, 2번째 배열 합친 값
			long long key = arr[0][i] + arr[1][j];

			// 이분 탐색 (내장 함수)로 인덱스 찾기
			long long low = lower_bound(v.begin(), v.end(), -key) - v.begin();
			long long high = upper_bound(v.begin(), v.end(), -key) - v.begin();

			// -한 값과 같다면
			if (-key == v[low]) {
				result += high - low;
			}
		}
	}

	cout << result << '\n';

	return 0;
}