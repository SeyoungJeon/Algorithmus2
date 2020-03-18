#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, cnt;
vector<pair<int, int>> meeting;

bool compare(const pair<int,int> &a, const pair<int, int> &b) {
	if (a.second < b.second) {
		return true;
	}
	else if (a.second == b.second) {
		// ȸ�ǰ� ������ �ð��� ������ ���� �ð� �������� �������� ����
		if (a.first < b.first) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// ȸ���� �� �Է� �ޱ�
	cin >> N;

	// ȸ�� �ð� �Է� �ޱ�
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		meeting.push_back({ start,end });
	}

	// ȸ�� �ð��� ������ �ð��� �������� ����
	sort(meeting.begin(), meeting.end(), compare);

	int current_End = 0;

	// ȸ�� �ð� ��ȸ
	for (auto k : meeting) {
		int start = k.first;
		int end = k.second;

		// ������ �ð��� ȸ�� �����ϴ� �ð����� �۴ٸ�
		if (current_End <= start) {
				current_End = end;
				cnt++;
		}
	}

	// ������ �ִ� ȸ�� ���� ���
	cout << cnt << '\n';

	return 0;
}