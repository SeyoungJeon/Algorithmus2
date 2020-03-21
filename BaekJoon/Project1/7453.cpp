#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long N, arr[4][4000];
vector<long long> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// �迭�� ���� �Է� �ޱ�
	cin >> N;

	// �� �迭�� ��� �Է� �ޱ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[j][i];
		}
	}

	// 3��° 4��° �迭 ��ġ��
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			v.push_back(arr[2][i] + arr[3][j]);
		}
	}

	// 3����, 4��° �迭 ��ģ �� �������� �����ϱ�
	sort(v.begin(), v.end());

	long long result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// 1��°, 2��° �迭 ��ģ ��
			long long key = arr[0][i] + arr[1][j];

			// �̺� Ž�� (���� �Լ�)�� �ε��� ã��
			long long low = lower_bound(v.begin(), v.end(), -key) - v.begin();
			long long high = upper_bound(v.begin(), v.end(), -key) - v.begin();

			// -�� ���� ���ٸ�
			if (-key == v[low]) {
				result += high - low;
			}
		}
	}

	cout << result << '\n';

	return 0;
}