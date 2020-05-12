#include <iostream>
#include <set>
#include <map>
#include <queue>

#define U 1
#define D 2
#define L 3
#define R 4

using namespace std;

struct Pos {
	int y;
	int x;
	int cnt;
	int dir;
};

int BFS(queue<Pos> q,int M,int N) {
	int result=0,time = 0;

	while (time < M) {
		size_t q_size = q.size();
		set<pair<int, int>> p;
		map<pair<int, int>, pair<int, int>> dirInfo;
		map<pair<int, int>, int> cntInfo;

		for (int s = 0; s < q_size; s++) {
			int y = q.front().y;
			int x = q.front().x;
			int cnt = q.front().cnt;
			int dir = q.front().dir;

			q.pop();

			int ny = y, nx = x, nc = cnt, nd = dir;

			switch (nd) {
			case U:
				ny--;
				break;
			case R:
				nx++;
				break;
			case D:
				ny++;
				break;
			case L:
				nx--;
				break;
			}

			if (ny < 1 || ny >= N - 1 || nx < 1 || nx >= N - 1) {
				nc /= 2;
				switch (nd) {
				case U:
					nd = D;
					break;
				case R:
					nd = L;
					break;
				case D:
					nd = U;
					break;
				case L:
					nd = R;
					break;
				}
			}

			if (nc == 0)
				continue;

			p.insert({ ny,nx });
			cntInfo[{ny, nx}] += nc;
			if (dirInfo[{ny, nx}].first < nc) {
				dirInfo[{ny, nx}].first = nc;
				dirInfo[{ny, nx}].second = nd;
			}
		}

		for (auto pos : p) {
			int ny = pos.first;
			int nx = pos.second;
			int nc = cntInfo[{ny, nx}];
			int nd = dirInfo[{ny, nx}].second;
			
			q.push({ ny,nx,nc,nd });
		}

		time++;
	}

	while (!q.empty()) {
		result += q.front().cnt;
		q.pop();
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;

	cin >> T;

	for (int test = 1; test <= T; test++) {
		int N, M, K, answer;
		queue<Pos> q;

		cin >> N >> M >> K;

		for (int i = 0; i < K; i++) {
			int y, x, cnt, dir;
			cin >> y >> x >> cnt >> dir;
			q.push({ y,x,cnt,dir });
		}

		answer = BFS(q,M,N);

		cout << "#" << test << ' ' << answer << '\n';
	}
	return 0;
}
