#include <iostream>

using namespace std;

int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// ���� ���� ���� �Է� �ޱ�
	cin >> N >> M;

	// �ּ� �ɰ��� Ƚ�� ���ϱ�
	int answer = N * M - 1;

	// ���� ���
	cout << answer << '\n';

	return 0;
}