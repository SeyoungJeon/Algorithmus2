#include <iostream>
#include <algorithm>

using namespace std;

int N,arr[1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// ������ ���� �Է� �ޱ�
	cin >> N;

	// �� ���� �Է� �ޱ�
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	// ���� ���� ����
	sort(arr, arr + N);

	int total = 0;
	for (int i = 0; i < N ; i++) {
		// ������ + 1 ���� ���Һ��� ���� ���
		if (total + 1 < arr[i]) {
			break;
		}

		// ������ ���
		total += arr[i];
	}

	// ���� ���
	cout << total + 1<< '\n';

	return 0;
}
