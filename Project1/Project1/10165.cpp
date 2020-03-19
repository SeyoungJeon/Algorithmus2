#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int N, M, max_end = -1 , min_start = INT_MAX;
vector<pair<pair<int, int>, int>> v1,v2;
vector<bool> answer;

// 시작 점 오름 차순, 끝 점 내림차순
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

	// 버스 정류장 개수 입력 받기
	cin >> N;

	// 버스 노선 수 입력 받기
	cin >> M;

	// 답 배열 초기화
	answer.resize(M + 1);

	// 버스 노선 입력 받기
	for (int i = 0; i < M; i++) {
		int a, b, temp;
		cin >> a >> b;
		if (a < b) {
			// 시계 방향
			v1.push_back({ {a,b},i + 1 });
		}
		else {
			// 반 시계 방향
			v2.push_back({ {a,b},i + 1 });

			// 반 시계 방향일 때 최소 시작점과 최대 끝점 저장
			min_start = min(min_start, a);
			max_end = max(max_end, b);
		}
	}

	// 시계 방향 배열 정렬
	sort(v1.begin(), v1.end(),compare);

	// 반 시계 방향 배열 정렬
	sort(v2.begin(), v2.end(), compare);

	int end = -1;

	// 시계 방향 배열 순회
	for (int i = 0; i < v1.size(); i++) {	
		int temp_s = v1[i].first.first;
		int temp_e = v1[i].first.second;

		// 반 시계 방향에 노선에 포함되어있다면
		if (temp_s >= min_start || temp_e <= max_end) {
			answer[v1[i].second] = true;
		}
		// 시계 방향 노선에 포함되어있다면
		else if (temp_e <= end) {
			answer[v1[i].second] = true;
		}
		// 끝 점 갱신
		else {
			end = temp_e;
		}
	}

	end = -1;

	// 반 시계 방향 배열 순회
	for (int i = 0; i < v2.size(); i++) {
		int temp_s = v2[i].first.first;
		int temp_e = v2[i].first.second;

		// 반 시계 방향 노선에 포함되어있다면
		if (temp_e <= end) {
			answer[v2[i].second] = true;
		}
		// 끝 점 갱신
		else {
			end = temp_e;
		}
	}

	for (int i = 1; i <= M; i++) {
		// 포함되어있지 않은 노선만 출력
		if (!answer[i]) {
			cout << i << ' ';
		}
	}
	cout << '\n';
	
	return 0;
}