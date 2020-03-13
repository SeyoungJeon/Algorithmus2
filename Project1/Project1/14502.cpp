#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int N, M, **map, **temp, dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} }, maxVal = 0;
bool **check;
deque<pair<int, int>> virus;
vector<pair<int, int>> safe;

void CountMaxSafeArea() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp[i][j] == 0) {
				cnt++;
			}
		}
	}

	if (maxVal < cnt)
		maxVal = cnt;
}

void CopyMap() {
	// 맵 정보 복사
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp[i][j] = map[i][j];
		}
	}
}

void BFS(deque<pair<int,int>> virus) {

	for (int i = 0; i < virus.size(); i++) {
		check[virus[i].first][virus[i].second] = true;
	}

	while (!virus.empty()) {
		int virus_y = virus.front().first;
		int virus_x = virus.front().second;

		virus.pop_front();

		// 바이러스 상,하,좌,우 이동
		for (int i = 0; i < 4; i++) {
			int ny = virus_y + dir[i][0];
			int nx = virus_x + dir[i][1];

			// map 범위 벗어나면 넘기기
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			// 다음 위치가 벽이라면 넘기기
			if (temp[ny][nx] == 1)
				continue;

			// 이미 바이러스가 있다면
			if (check[ny][nx])
				continue;

			check[ny][nx] = true;
			temp[ny][nx] = 2;
			virus.push_back({ ny,nx });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 가로 세로 입력 받기
	cin >> N >> M;

	// map, temp, check 초기화
	map = new int*[N];
	temp = new int*[N];
	check = new bool*[N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[M];
		temp[i] = new int[M];
		check[i] = new bool[M];
	}

	// 맵 정보 입력 받기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			temp[i][j] = map[i][j];

			if (map[i][j] == 0) {
				// 안전 지역
				safe.push_back({ i,j });
			}
			else if (map[i][j] == 2) {
				// 바이러스 일 경우
				virus.push_front({ i,j });
			}
		}
	}

	for (int i = 0; i < safe.size(); i++) {
		for (int j = i + 1; j < safe.size(); j++) {
			for (int k = j + 1; k < safe.size(); k++) {
				// 벽 3개 선택
							
				// 벽 설치
				temp[safe[i].first][safe[i].second] = 1;
				temp[safe[j].first][safe[j].second] = 1;
				temp[safe[k].first][safe[k].second] = 1;

				// 방문 변수 초기화
				for (int i = 0; i < N; i++) {
					fill_n(check[i], M, false);
				}

				// BFS
				BFS(virus);

				// 최대 안전 지역 세기
				CountMaxSafeArea();

				// map 초기화
				CopyMap();

			}
		}
	}

	cout << maxVal << '\n';

	return 0;
}