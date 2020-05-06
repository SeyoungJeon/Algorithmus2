#include <iostream>
#include <queue>
#include <map>
#include <set>

using namespace std;

struct plant {
	int y;
	int x;
	int life;
	int state;
	int original;
};

int T, dir[4][2] = { {-1,0}, {1,0},{0,-1},{0,1} };
int N, M, K, answer;

int BFS(map<pair<int, int>, int> map2, queue<plant> q) {
	int time = 0, count;

	while (!q.empty()) {
		size_t s = q.size();
		//cout << "TIME, SIZE : " << time << ' ' <<  s << '\n';
		set<pair<int, int>> temp;
		map<pair<int, int>, int> m;

		for (int i = 0; i < s; i++) {
			int curY = q.front().y;
			int curX = q.front().x;
			int curLife = q.front().life;
			int curState = q.front().state;
			int curOriginal = q.front().original;

			//cout << curY << ' ' << curX << ' ' << curState << '\n';

			q.pop();

			if (curState == 2) {
				for (int j = 0; j < 4; j++) {
					int ny = curY + dir[j][0];
					int nx = curX + dir[j][1];

					// 주위에 이미 식물이 심어져있다면
					if (map2[{ny, nx}] != 0)
						continue;

					// 다음 위치
					temp.insert({ ny,nx });
					if (m[{ny, nx}] < curOriginal)
						m[{ny, nx}] = curOriginal;
				}
			}

			// 생명력 감소
			curLife--;

			if (curState == 2) {
				// 활성화 상태
				if (curLife == 0) {
					curState = 0;
				}
			}
			else if (curState == 1) {
				// 비활성화 상태
				if (curLife == 0) {
					curState = 2;
					curLife = curOriginal;
				}
			}

			if (curState == 0)
				continue;

			q.push({ curY,curX,curLife,curState,curOriginal });
		}

		for (auto w : temp) {
			int ny = w.first;
			int nx = w.second;
			int life = m[{ny, nx}];
			map2[{ny, nx}] = 1;
			q.push({ ny,nx,life,1,life });
		}

		time++;

		if (time == K)
		{
			count = q.size();
			break;
		}
	}

	return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Test 수 입력
	cin >> T;

	for (int test = 1; test <= T; test++) {

		// N,M,K 입력
		cin >> N >> M >> K;

		queue<plant> q;
		map<pair<int, int>, int> m;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int life;

				cin >> life;

				if (life != 0) {
					m.insert({ {i,j}, 1 });
					q.push({ i,j,life,1,life });
				}
			}
		}

		answer = BFS(m, q);

		cout << "#" << test << ' ' << answer << '\n';
	}

	return 0;
}