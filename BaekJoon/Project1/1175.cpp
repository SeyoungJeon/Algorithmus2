#include <iostream>
#include <vector>
#include <queue>
#include <string>

#define MAX 50

using namespace std;

struct Pos {
	int y;
	int x;
	int d;
	int cnt;
	bool Cfind;
	bool Dfind;
};

int N, M, dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
string *map;
bool visit[MAX][MAX][4][2][2];	// 세로,가로,방향,C, D

int BFS(queue<Pos> q) {
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int d = q.front().d;
		int cnt = q.front().cnt;
		bool Cfind = q.front().Cfind;
		bool Dfind = q.front().Dfind;
		q.pop();

		if (Cfind && Dfind) {
			return cnt;
		}

		for (int i = 0; i < 4; i++) {
			if (i == d)
				continue;

			int ny = y + dir[i][0];
			int nx = x + dir[i][1];
			bool nCfind = Cfind;
			bool nDfind = Dfind;

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			if (visit[ny][nx][i][Cfind][Dfind] || map[ny][nx] == '#')
				continue;

			if (map[ny][nx] == 'C')	nCfind = true;
			if (map[ny][nx] == 'D')	nDfind = true;
			
			visit[ny][nx][i][nCfind][nDfind] = true;
			q.push({ ny,nx,i,cnt + 1,nCfind,nDfind });			
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	queue<Pos> q;

	cin >> N >> M;

	map = new string[N];
	
	bool C = false;
	for (int i = 0; i < N; i++) {
		cin >> map[i];

		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j] == 'S') {
				map[i][j] = '.';
				q.push({ i,j,-1,0,0,0 });
			}
			else if (map[i][j] == 'C') {
				if (!C) {
					C = true;
				}
				else {
					map[i][j] = 'D';
				}
			}
		}
	}

	cout << BFS(q) << '\n';

	return 0;
}