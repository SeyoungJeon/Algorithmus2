#include <iostream>
#include <limits.h>
#include <stack>
#include <deque>

using namespace std;

char *str;
int N;
int answer = INT_MIN;

deque<int> q;
bool *arr;

int  Calculate(int a, int b, char operate) {
	int result = 0;
	switch (operate) {
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	default:
		break;
	}

	return result;
}

void DFS(int depth,int k,int cur) {
	if (depth > k) {
		fill_n(arr, N, false);

		deque<int> number;
		deque<char> operate;

		for (auto k : q) {
			arr[k] = true;
		}
	
		for (int i = 0; i < N; i++) {
			if (arr[i] == 0 && i % 2 == 0) {
				number.push_back(str[i]-48);
			}
			else if (arr[i] == 0 && i % 2 == 1) {
				operate.push_back(str[i]);
			}
			else if(arr[i] == 1) {
				number.push_back(Calculate(str[i] - 48, str[i + 2] - 48, str[i + 1]));
				i += 2;
			}
		}

		int result = number.front();
		number.pop_front();

		while (!operate.empty()) {
			result = Calculate(result, number.front(), operate.front());
			number.pop_front();
			operate.pop_front();
		}

		if (answer < result)
			answer = result;
		
		return ;
	}

	for (int i = cur; i < N - 1; i+=2) {
		if (!q.empty() && (q.back() + 2 == i || q.back() == i))
			continue;

		q.push_back(i);
		DFS(depth + 1, k, i);
		q.pop_back();
	}
	
}

int main() {
	cin >> N;
	str = new char[N];
	arr = new bool[N];

	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}
	
	if (N == 1) {
		answer = str[0] - 48;
	}
	else {
		for (int i = 0; i < ((N + 1) / 2) / 2; i++) {
			DFS(0, i, 0);
		}
	}

	cout << answer << '\n';

	delete[] str;
	delete[] arr;

	return 0;
}