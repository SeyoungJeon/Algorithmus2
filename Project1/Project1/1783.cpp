#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// ���� ���� �Է� �ޱ�
	cin >> N >> M;

	int cnt = 1;
	
	/* ���̿� ���� �ܰ踦 �����ִ°� �߿� ! */

	if (N == 2) {
		// ���̰� 2���
		cnt = min(4, (M+1) / 2);
	}
	else if (N >= 3) {
		// ���̰� 3 �̻��̶��
		if (M < 7) {
			// ��� �̵������ ����� �� ���� ���
			cnt = min(4, M);
		}
		else {
			// ��� �̵������ ����� �� �ִ� ���
			cnt = M - 2;
		}
	}
	cout << cnt << '\n';

	return 0;
}