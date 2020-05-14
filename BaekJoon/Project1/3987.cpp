#include <iostream>
#include <string>

#define U 0
#define R 1
#define D 2
#define L 3

using namespace std;

int N, M, PR, PC, dir[4][2] = { {-1,0},{0,1},{1,0}, {0,-1} }, answer = -1;
char map[500][500], answerDir;
bool visit[500][500][4][4], infinite = false;

void DirToChar(int dir) {
	switch (dir) {
	case U:
		answerDir = 'U';
		break;
	case R:
		answerDir = 'R';
		break;
	case D:
		answerDir = 'D';
		break;
	case L:
		answerDir = 'L';
		break;
	}
}

void DFS(int depth, int row, int col, int cd, int sd) {
	if ((row < 0 || row >= N || col < 0 || col >= M) ||
		map[row][col] == 'C') {

		if (answer < depth){
			DirToChar(sd);
			answer = depth;
		}

		return;
	}
	else if (visit[row][col][cd][sd]) {
		DirToChar(sd);
		infinite = true;
		return;
	}
	else if (map[row][col] == '/') {
		switch (cd) {
		case U:
			cd = R;
			break;
		case R:
			cd = U;
			break;
		case D:
			cd = L;
			break;
		case L:
			cd = D;
			break;
		}
	}
	else if (map[row][col] == '\\'){
		switch (cd) {
		case U:
			cd = L;
			break;
		case R:
			cd = D;
			break;
		case D:
			cd = R;
			break;
		case L:
			cd = U;
			break;
		}
	}

	visit[row][col][cd][sd] = true;

	int ny = row + dir[cd][0];
	int nx = col + dir[cd][1];
	
	DFS(depth + 1, ny, nx, cd, sd);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;

		for (int j = 0; j < M; j++) {
			map[i][j] = input[j];
		}
	}

	cin >> PR >> PC;

	for (int i = 0; i < 4; i++) {
		DFS(0, PR-1, PC-1, i, i);

		if (infinite) {
			break;
		}
	}

	cout << answerDir << '\n';
	if (infinite) {
		cout << "Voyager" << '\n';
	}
	else {
		cout << answer << '\n';
	}

	return 0;
}