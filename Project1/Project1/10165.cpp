#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int N, M, max_end = -1 , min_start = INT_MAX;
vector<pair<pair<int, int>, int>> v1,v2;
vector<bool> answer;

// ���� �� ���� ����, �� �� ��������
bool compare(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
	if (a.first.first < b.first.first) {
		return true;
	}
	else if ((a.first.first == b.first.first) &&
		(a.first.second > b.first.second)) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// ���� ������ ���� �Է� �ޱ�
	cin >> N;

	// ���� �뼱 �� �Է� �ޱ�
	cin >> M;

	// �� �迭 �ʱ�ȭ
	answer.resize(M + 1);

	// ���� �뼱 �Է� �ޱ�
	for (int i = 0; i < M; i++) {
		int a, b, temp;
		cin >> a >> b;
		if (a < b) {
			// �ð� ����
			v1.push_back({ {a,b},i + 1 });
		}
		else {
			// �� �ð� ����
			v2.push_back({ {a,b},i + 1 });

			// �� �ð� ������ �� �ּ� �������� �ִ� ���� ����
			min_start = min(min_start, a);
			max_end = max(max_end, b);
		}
	}

	// �ð� ���� �迭 ����
	sort(v1.begin(), v1.end(),compare);

	// �� �ð� ���� �迭 ����
	sort(v2.begin(), v2.end(), compare);

	int end = -1;

	// �ð� ���� �迭 ��ȸ
	for (int i = 0; i < v1.size(); i++) {	
		int temp_s = v1[i].first.first;
		int temp_e = v1[i].first.second;

		// �� �ð� ���⿡ �뼱�� ���ԵǾ��ִٸ�
		if (temp_s >= min_start || temp_e <= max_end) {
			answer[v1[i].second] = true;
		}
		// �ð� ���� �뼱�� ���ԵǾ��ִٸ�
		else if (temp_e <= end) {
			answer[v1[i].second] = true;
		}
		// �� �� ����
		else {
			end = temp_e;
		}
	}

	end = -1;

	// �� �ð� ���� �迭 ��ȸ
	for (int i = 0; i < v2.size(); i++) {
		int temp_s = v2[i].first.first;
		int temp_e = v2[i].first.second;

		// �� �ð� ���� �뼱�� ���ԵǾ��ִٸ�
		if (temp_e <= end) {
			answer[v2[i].second] = true;
		}
		// �� �� ����
		else {
			end = temp_e;
		}
	}

	for (int i = 1; i <= M; i++) {
		// ���ԵǾ����� ���� �뼱�� ���
		if (!answer[i]) {
			cout << i << ' ';
		}
	}
	cout << '\n';
	
	return 0;
}