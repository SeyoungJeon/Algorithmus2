#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const int &a, const int &b) {
	return a > b;
}

int solution(vector<int> citations) {
	int answer = 0;
	
	// ���� ���� ����
	sort(citations.begin(), citations.end(),compare);

	int max_val = citations[0];

	// �ִ񰪺��� �Ųٷ� ��ȸ
	for (int i = max_val; i >= 0; i--) {
		int left = 0;
		int right = 0;

		// �迭 ��ȸ
		for (int j = 0; j < citations.size() ; j++) {
			// �ο�� �� ���� ����
			if (i <= citations[j])
				left++;
			else{
				break;
			}
		}

		// �ο�� �� ������ i ���� ũ�ų� ���ٸ�
		if (left >= i)
		{
			answer = i;
			break;
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> s;/*
	s.push_back(3);
	s.push_back(0);
	s.push_back(6);
	s.push_back(1);
	s.push_back(5);*/

	s.push_back(1);
	s.push_back(1);
	s.push_back(0);
	s.push_back(0);

	

	solution(s);

	return 0;
}