#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int x, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// ������ �ʺ� �Է� �ޱ�
	while (cin >> x) {

		// ���� ��ȯ
		x *= 1e7;

		// ���� ������ ���� �Է� �ޱ�
		cin >> n;

		vector<int> v(n);

		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		// �� ���� �������� �����ϱ�
		sort(v.begin(), v.end());

		int left = 0, right = n-1;
		bool find = false;
		while (left < right) {

			if (v[left] + v[right] > x) {
				// �� �� ���� ���� x �� ���� ũ�ٸ�
				right--;
			}
			else if (v[left] + v[right] < x) {
				// �� �� ���� ���� x �� ���� ������
				left++;
			}
			else {
				// �� �� ���� ���� x ���� ������
				find = true;
				cout << "yes " << v[left] << ' ' << v[right] << '\n';
				break;
			}
		}

		if (!find) {
			// ���̿� �´� ���� ã�� ���Ѵٸ�
			cout << "danger" << '\n';
		}
	}
	return 0;
}