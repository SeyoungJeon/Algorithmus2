#include <iostream>
#include <set>
#include <limits.h>
#include <vector>
#include <algorithm>

#define NN 1
#define E 2
#define S 3
#define W 4

using namespace std;

struct Island {
	int num;
	int val;
};

struct KS {
	int from;
	int to;
	int val;
};

vector<KS> ks;
set<pair<int,int>> *v;
int N, M, **map, answer = 0, dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int *parent;
bool **visit,*visit2,chk;

bool compare(const KS &a, const KS &b) {
	return a.val < b.val;
}

// 파인드
int find(int u) {
	if (u == parent[u]) {
		return u;
	}

	return parent[u] = find(parent[u]);
}

// 유니온
void merge(int u, int v) {
	chk = false;
	u = find(u);
	v = find(v);

	// 사이클 존재 여부 확인 코드
	if (u == v)
		return;

	parent[u] = v;
	chk = true;
}

void DFS2(int row,int col,int dir,int start,int len) {
	switch (dir) {
	case NN:
		row--;
		break;
	case E:
		col++;
		break;
	case S:
		row++;
		break;
	case W:
		col--;
		break;
	}

	if (row < 0 || row >= N || col < 0 || col >= M)
		return;

	if (map[row][col] == start)
		return;

	if (map[row][col] != 0 && map[row][col] != start) {
		if (len >= 2) {
			v[start].insert({ map[row][col],len });
		}
		return;
	}

	DFS2(row, col, dir, start, len + 1);
}

void DFS(int row, int col,int pos) {
	
	map[row][col] = pos;
	visit[row][col] = true;

	for (int i = 0; i < 4; i++) {
		int ny = row + dir[i][0];
		int nx = col + dir[i][1];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;

		if (!map[ny][nx])
			continue;

		if (visit[ny][nx])
			continue;

		DFS(ny, nx, pos);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 가로 세로 입력 받기
	cin >> N >> M;

	// 공간 초기화
	map = new int*[N];
	visit = new bool*[N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[M];
		visit[i] = new bool[M];
		fill_n(visit[i], M, false);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int cnt = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0 || visit[i][j])
				continue;

			DFS(i, j, cnt);
			cnt++;
		}
	}

	parent = new int[cnt];
	for (int i = 0; i < cnt; i++) {
		parent[i] = i;
	}
	v = new set<pair<int,int>>[cnt];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != 0) {
				DFS2(i, j, NN, map[i][j], 0);
				DFS2(i, j, E, map[i][j], 0);
				DFS2(i, j, S, map[i][j], 0);
				DFS2(i, j, W, map[i][j], 0);
			}
		}
	}

	for (int i = 1; i < cnt; i++) {
		int from = i;
		for (auto k : v[i]) {
			int to = k.first;
			int val = k.second;
			ks.push_back({ from,to,val });
		}
	}

	// 가중치 오름차순 정렬
	sort(ks.begin(), ks.end(), compare);
	
	int count = 0;
	// MST 크루스칼 알고리즘
	for (int i = 0; i < ks.size(); i++) {
		int from = ks[i].from;
		int to = ks[i].to;

		merge(from, to);

		if (chk){
			answer += ks[i].val;
			count++;
		}
	}

	if (count != cnt - 2)
		answer = -1;

	cout << answer << '\n';

	return 0;
}
