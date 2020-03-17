#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int x, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 구멍의 너비 입력 받기
	while (cin >> x) {

		// 단위 변환
		x *= 1e7;

		// 레고 조각의 개수 입력 받기
		cin >> n;

		vector<int> v(n);

		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		// 각 조각 오름차순 정렬하기
		sort(v.begin(), v.end());

		int left = 0, right = n-1;
		bool find = false;
		while (left < right) {

			if (v[left] + v[right] > x) {
				// 양 끝 값의 합이 x 값 보다 크다면
				right--;
			}
			else if (v[left] + v[right] < x) {
				// 양 끝 값의 합이 x 값 보다 작으면
				left++;
			}
			else {
				// 양 끝 값의 합이 x 값과 같으면
				find = true;
				cout << "yes " << v[left] << ' ' << v[right] << '\n';
				break;
			}
		}

		if (!find) {
			// 길이에 맞는 레고를 찾지 못한다면
			cout << "danger" << '\n';
		}
	}
	return 0;
}