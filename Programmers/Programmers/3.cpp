#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

bool compare(const int &a, const int &b) {
	if (a > b) {
		return true;
	}
	else {
		return false;
	}
}

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;

	// A �迭 ���� ���� ����
	sort(A.begin(), A.end());

	// B �迭 ���� ���� ����
	sort(B.begin(), B.end(), compare);

	size_t v_size = A.size();
	for (int i = 0; i < v_size; i++) {
		answer += A[i] * B[i];
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> A, B;
	// ���� ���� 1
	/*A.push_back(1);
	A.push_back(4);
	A.push_back(2);
	B.push_back(5);
	B.push_back(4);
	B.push_back(4);*/
	
	// ���� ���� 2
	A.push_back(1);
	A.push_back(2);
	B.push_back(3);
	B.push_back(4);

	cout << solution(A, B) << '\n';

	return 0;
}