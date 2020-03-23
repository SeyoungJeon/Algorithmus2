#include <iostream>

using namespace std;

int N, M, K;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// ���л� ��, ���л� ��, ���Ͻ��� �����ؾ��ϴ� �ο� �Է� �ޱ�
	cin >> N >> M >> K;

	int cnt = 0;
	
	// ���л� �� ���л� �� ���� �̷�� ������ K �ο����� �̻��� ��� 
	// ���л��� 2���̻�, ���л��� 1���̻� �������� ���
	while (N-2 + M-1 >= K && N >= 2 && M >= 1) {
		N -= 2;
		M -= 1;

		// �� ���� ����
		cnt++;
	}

	// ���� ���
	cout << cnt << '\n';

	return 0;
}