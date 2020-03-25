#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	int idx = 0;
	priority_queue<int, vector<int>, less<int>> pq;

	// �а��� ���� k ���� ���� ���
	while (stock < k) {
		// �а��� ���� ��¥ ���� ũ�ų� ������ �켱���� ť�� ����
		// �ڵ����� ���� ���� �а��� ���� �������� ���� 
		for (int i = idx; i < dates.size() && stock >= dates[i] ;i++) {
			pq.push(supplies[i]);
			idx++;
		}

		stock += pq.top();
		pq.pop();
		answer++;
	}

	cout << answer << '\n';

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solution(4, { 4,10,15 }, { 20,5,10 }, 30);
	return 0;
}