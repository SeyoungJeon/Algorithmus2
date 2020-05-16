#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <limits.h>

using namespace std;

vector<pair<int, char>> oper;
int N,answer = INT_MIN;
string input;
bool visit[10];

void DFS(int depth, int end, vector<pair<int,int>> temp) {
	if (depth >= end) {
		// 연산자 우선순위를 정한 후, 문자열 조정해서 답 최댓값구하기
		// 다른 사람들보다 수행시간이 길다..
		string str = input;
		for (int i = 0; i < temp.size(); i++) {
			int pos = temp[i].first;
			char op = temp[i].second;
		
			int left = pos - 1;
			string leftStr = "";
			while (left >= 0 && ('0' <= str[left] && str[left] <= '9'
				|| str[left] == '.')) {
				leftStr = str[left] + leftStr;
				left--;
			}

			int right = pos + 1;
			string rightStr = "";
			while (right < str.size() && ('0' <= str[right] && str[right] <= '9'
				|| str[right] == '.')) {
				rightStr += str[right];
				right++;
			}

			left++;

			if (leftStr[0] == '.') {
				leftStr[0] = '-';
			}
			if (rightStr[0] == '.') {
				rightStr[0] = '-';
			}

			
			int leftVal = stoi(leftStr), rightVal = stoi(rightStr);

			int result = -1;
			switch (op) {
			case '+':
				result = leftVal + rightVal;
				break;
			case '-':
				result = leftVal - rightVal;
				break;
			case '*':
				result = leftVal * rightVal;
				break;
			}
			
			string resultStr = to_string(result);
			if (resultStr[0] == '-') {
				resultStr[0] = '.';
			}
			
			int dif = abs(pos - left) + abs(pos - right) - resultStr.size();

			string plusLeft = str.substr(0, left);
			string plusRight = str.substr(right);


			str = plusLeft + resultStr + plusRight;

			for (int j = i + 1; j < temp.size(); j++) {
				if (temp[j].first > pos) {
					temp[j].first -= dif;
				}
			}

		}
		if (str[0] == '.')
			str[0] = '-';

		int res = stoi(str);
		if (answer < res)
			answer = res;

		return;
	}

	for (int i = 0; i < oper.size(); i++) {
		if (visit[i])
			continue;

		visit[i] = true;
		temp.push_back(oper[i]);
		DFS(depth + 1, end, temp);
		temp.pop_back();
		visit[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	cin >> input;

	for (int i = 0; i < N; i++) {
		if (!('0' <= input[i] && input[i] <= '9')) {
			oper.push_back({ i,input[i] });
		}
	}

	DFS(0, oper.size(),vector<pair<int,int>>());

	cout << answer << '\n';
	return 0;
}