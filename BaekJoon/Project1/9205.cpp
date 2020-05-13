#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

struct Pos {
	int y;
	int x;
};

bool *visit,check;
vector<Pos> v;
int t, n;

bool BFS(queue<Pos> q,int ey,int ex)
{
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;

		q.pop();

		int target_dif = abs(ey - y) + abs(ex - x);
	
		// 50으로 나누면 나머지 발생 시 오답
		if (target_dif <= 1000) {
			return true;
		}

		for (int i = 0; i < v.size(); i++) {
			Pos temp = v[i];

			int dif = abs(y - temp.y) + abs(x - temp.x);
	
			if (dif > 1000)
				continue;

			if (visit[i])
				continue;

			visit[i] = true;
			q.push(temp);
		}
	}

	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;

	for (int test = 0; test < t; test++) {
		cin >> n;

		int sy, sx, ey, ex;
		queue<Pos> q;
		v.clear();
		visit = new bool[n];
		fill_n(visit, n, false);
		check = false;
		cin >> sx >> sy;
		q.push({ sy,sx });

		for (int i = 0; i < n; i++) {
			int y, x;
			cin >> x >> y;
			v.push_back({ y,x });
		}

		cin >> ex >> ey;

		check = BFS(q,ey,ex);

		if (check) {
			cout << "happy" << '\n';
		}
		else {
			cout << "sad" << '\n';
		}
	}

	return 0;
}