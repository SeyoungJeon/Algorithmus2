#include <iostream>
#include <vector>

using namespace std;

int n, percent[4] , dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
vector<pair<int, int>> map;
vector<int> m;
double cal = 0;

// 해당 위치에 방문 여부
bool IsVisit(int row, int col) {
	for (int i = 0; i < map.size(); i++) {
		if (map[i].first == row && map[i].second == col)
			return true;
	}

	return false;
}

void DFS(int depth,int row, int col) {
	if (depth == n) {
		double temp = 1;

		// 한 가지 경우의 수 확률 계산
		for (auto k : m) {
			temp *= (double)percent[k] / 100.0;
		}
		cal += temp;
		
		return;
	}

	// 백트래킹
	for (int i = 0; i < 4; i++) {
		int ny = row + dir[i][0];
		int nx = col + dir[i][1];

		if (IsVisit(ny,nx))
			continue;

		m.push_back(i);
		map.push_back({ ny,nx });
		DFS(depth + 1,ny,nx);
		map.pop_back();
		m.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 로봇 행동 개수 입력 받기
	cin >> n;

	// 각 방향 확률 입력 받기
	for (int i = 0; i < 4; i++) {
		cin >> percent[i];
	}

	// 초기 방문 지점
	map.push_back({ 0,0 });

	// 탐색
	DFS(0,0,0);

	// 소수점 9자리까지 출력 설정
	cout.precision(9);

	// 정답 출력
	cout << cal << '\n';

	return 0;
}