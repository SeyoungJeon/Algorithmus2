#include <iostream>
#include <vector>

using namespace std; 

int N, K, cnt = 0;
vector<int> coins;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int end;
	
	// ������ ����, ��ǥ �� �Է� �ޱ�
	cin >> N >> K;

	// N ���� ���� �Է� �ޱ�
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		coins.push_back(input);

		// ��ǥ�ϴ� ������ ���� ����ġ�� Ŀ���� ���� ���� �� ����
		if (input < K)
			end = i;
	}

	// ���������� ��ȸ
	for (int i = end; i >= 0; i--) {
		// ��ǥ�ϴ� ���� �����ϸ�
		if (K == 0) {
			break;
		}

		// ������ cnt ����
		cnt += K / coins[i];

		// ����ġ ����
		K %= coins[i];
	}
	
	// ���� ���
	cout << cnt << '\n';
	
	/* ó�� Ǭ ���
	// ������ ������ ���������� ��ȸ
	while (true) {
		if (K < coins[end]) {
			// ��ǥ�ϴ� �� ���� ���� ũ��
			end--;
		}
		else if (K >= coins[end]) {
			// ��ǥ�ϴ� �� ���� ���� ������
			K -= coins[end];
			cnt++;
		}

		if (K == 0) {
			// ��ǥ�ϴ� ���� �� ä���ٸ�
			break;
		}
	} 

	// ���� ���
	cout << cnt << '\n';
	*/

	return 0;
}