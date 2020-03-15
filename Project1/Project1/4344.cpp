#include <iostream>

using namespace std;

int C, N, *grade;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// C++ ��� ���� ����
	cout << fixed;
	cout.precision(3);

	// �׽�Ʈ ���̽� ���� �Է� �ޱ�
	cin >> C;

	// �׽�Ʈ ���̽� �Է� �ޱ�
	for (int i = 0; i < C; i++) {
		float avg = 0;
		int studentCnt = 0, total = 0;
		// �л� �� �Է� �ޱ�
		cin >> N;

		// �л����� ���� �迭 �ʱ�ȭ
		grade = new int[N];
		
		// �л����� ���� �Է� �ޱ�
		for (int j = 0; j < N; j++) {
			cin >> grade[j];
			total += grade[j];
		}

		// ��� ���
		avg = total / N;

		for (int j = 0; j < N; j++) {
			// ��� ���� �л� ����
			if (avg < grade[j])
				studentCnt++;
		}

		// ��� ���� �л� ���� ���
		// C���
//		printf("%0.3f%%\n", ((double)studentCnt / (double)N) * 100);
			
		cout << ((float)studentCnt / (float)N) * 100 << "%\n";
	}

	return 0;
}