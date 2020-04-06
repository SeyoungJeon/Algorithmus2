#include <iostream>
#include <map>

using namespace std;

int T, n;
map<int, int> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//// �� ���� ���� �ִ� ���ϱ�
	//for (int i = 1; i <= 100000; i++) {
	//	int temp = i;
	//	int tempAnswer = i;
	//	
	//	bool find = false;

	//	while (temp != 1) {
	//		// ���� ���� �����Ѵٸ� while�� ���߱�
	//		if (m[temp] != 0) {
	//			// �����ϴ� ���� ���� �ִ��� ��
	//			if (m[temp] > tempAnswer) {
	//				m[i] = m[temp];
	//				find = true;
	//			}
	//			break;
	//		}

	//		if (tempAnswer < temp)
	//			tempAnswer = temp;

	//		if (temp % 2 == 0) {
	//			temp /= 2;
	//		}
	//		else {
	//			temp = temp * 3 + 1;
	//		}
	//	}
	//
	//	if(!find)
	//		m[i] = tempAnswer;
	//
	//}

	// �׽�Ʈ ���̽� ���� �Է� �ޱ�
	cin >> T;

	for (int i = 0; i < T; i++) {
		// �� �Է� �ޱ�
		cin >> n;

		int answer = n;
		while (n != 1) {
			if (n > answer)
				answer = n;

			if (n % 2 == 0) {
				n /= 2;
			}
			else {
				n = n * 3 + 1;
			}
		}

		cout << answer << '\n';

	}

	return 0;
}