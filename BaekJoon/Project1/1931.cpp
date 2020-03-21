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
		// 회의가 끝나는 시간이 같으면 시작 시간 기준으로 오름차순 정렬
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

	// 회의의 수 입력 받기
	cin >> N;

	// 회의 시간 입력 받기
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		meeting.push_back({ start,end });
	}

	// 회의 시간이 끝나는 시간을 기준으로 정렬
	sort(meeting.begin(), meeting.end(), compare);

	int current_End = 0;

	// 회의 시간 순회
	for (auto k : meeting) {
		int start = k.first;
		int end = k.second;

		// 끝나는 시간이 회의 시작하는 시간보다 작다면
		if (current_End <= start) {
				current_End = end;
				cnt++;
		}
	}

	// 가능한 최대 회의 개수 출력
	cout << cnt << '\n';

	return 0;
}