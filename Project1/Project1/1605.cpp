#include <iostream>
#include <string>

using namespace std;

int L;
string input;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 문자 개수 입력 받기
	cin >> L;

	// 문자열 입력 받기
	cin >> input;
	
	bool find = false;
	for (int i = L/2; i >= 1; i--) {
		// 문자 개수 
		int end;
		if ((L / 2) % 2 == 1) {
			// 홀수
			end = L - i + 1;
		}
		else {
			// 짝수
			end = L - i;
		}

		for (int j = 0; j <= end ; j++) {
			// 문자 시작 
			cout << "J : " << j << '\n';
			cout << "I : " << i << '\n';
			string temp = input.substr(j, i);
			cout << temp << '\n';
			
			if (input.find(temp,i+j+1) != string::npos) {
				cout << "찾은 위치 : " << input.find(temp, i + 1) << '\n';
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