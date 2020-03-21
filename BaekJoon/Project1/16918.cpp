#include <iostream>
#include <deque>

using namespace std;

int dir[5][2] = { { 1,0},{-1,0},{0,1},{0,-1}, {0,0} };
int R, C, N;
char **map;
deque<pair<int,int>> bombs;

void BFS() {

	while (!bombs.empty()) {

		int y = bombs.front().first;
		int x = bombs.front().second;

		bombs.pop_front();

		for (int i = 0; i < 5; i++) {
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (ny < 0 || ny >= R || nx < 0 || nx >= C)
				continue;

			map[ny][nx] = '.';
		}
		
	}
}

// ºó °ø°£¿¡ ÆøÅº Ã¤¿ì±â
void Fill_Bomb() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == '.') {
				map[i][j] = 'O';
			}
			else {
				bombs.push_front({ i,j });
			}
		}
	}
}

int main() {
	int time = 0;

	cin >> R >> C >> N;

	map = new char*[R];
	for (int i = 0; i < R; i++)
		map[i] = new char[C];

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	while (time < N) {

		if (time == 0) {

			if (N == time)
				break;
			
			time++;
			continue;
		}

		if(time % 2 == 1){
			Fill_Bomb();
		}
		else {
			BFS();
		}

		time++;
		
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
	cout << '\n';

	for (int i = 0; i < R; i++) {
		delete[] map[i];
	}

	return 0;
}