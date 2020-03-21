#include <iostream>
#include <stack>

using namespace std;

int N;
stack<pair<int,int>> arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// ž�� ���� �Է� �ޱ�
	cin >> N;

	// ž ���� �Է� �ޱ�
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		
		// Stack�� ������� �ʴٸ�
		while (!arr.empty()) {

			// ž�� ��ȣ�� ���� �����ϴٸ�
			if (arr.top().first > input) {
				cout << arr.top().second + 1 << ' ';
				break;
			}
			arr.pop();
		}
		
		// ���� ������ ž�� ���ٸ�
		if (arr.empty()) {
			cout << 0 << ' ';
		}

		// ž�� ���̿� ��ġ �߰�
		arr.push({ input,i });
	}

	cout << '\n';
	return 0;
}