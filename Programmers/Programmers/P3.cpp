#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	int len = number.size() - k;

	char temp;
	int pos = 0;
	int size = len - 1;
	while (true) {
		temp = number[pos];
		bool find = false;
		for (int i = pos + 1; i < number.size() - size ; i++) {
			if (temp < number[i]) {
				temp = number[i];
				pos = i;
				find = true;
			}
		}

		pos += 1;
		answer += temp;
		size -=1 ;

		if (answer.size() == len)
			break;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << solution("1924", 2) << '\n';
	cout << solution("1231234", 3) << '\n';

	
	cout << solution("4177252841", 4) << '\n';

	return 0;
}