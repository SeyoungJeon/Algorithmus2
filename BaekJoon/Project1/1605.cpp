#include <iostream>
#include <string>

using namespace std;

int L;
string input;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// ���� ���� �Է� �ޱ�
	cin >> L;

	// ���ڿ� �Է� �ޱ�
	cin >> input;
	
	bool find = false;
	for (int i = L/2; i >= 1; i--) {
		// ���� ���� 
		int end;
		if ((L / 2) % 2 == 1) {
			// Ȧ��
			end = L - i + 1;
		}
		else {
			// ¦��
			end = L - i;
		}

		for (int j = 0; j <= end ; j++) {
			// ���� ���� 
			cout << "J : " << j << '\n';
			cout << "I : " << i << '\n';
			string temp = input.substr(j, i);
			cout << temp << '\n';
			
			if (input.find(temp,i+j+1) != string::npos) {
				cout << "ã�� ��ġ : " << input.find(temp, i + 1) << '\n';
				find = true;
				cout << i << '\n';
				break;
			}
		}	
		if (find)
			break;
	}

	if (!find)
		cout << 0 << '\n';

	return 0;
}