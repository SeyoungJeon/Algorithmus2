#include <iostream>

using namespace std;

int map[3][3];
bool check[3][3];
int sp_y, sp_x, ans = 987654321, dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

bool Check_Map() {
	bool check = true;
	int check_num = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 2 && j == 2)
				break;

			if (map[i][j] == check_num) {
				check_num++;
			}
			else {
				check = false;
			}
		}
		if (!check)
			break;
	}
	
	return check;
}

void DFS(int row,int col,int result) {
	if (Check_Map()) {
		if (ans > result) {
			ans = result;
		}
		return;
	}


	for (int i = 0; i < 4; i++) {
		int ny = row + dir[i][0];
		int nx = col + dir[i][1];

		if (ny < 0 || ny >= 3 || nx < 0 || nx >= 3)
			continue;

		if (check[ny][nx])
			continue;

		check[ny][nx] = true;
		int temp = map[ny][nx];
		map[row][col] = temp;
		map[ny][nx] = 0;

		DFS(ny, nx,result+1);

		map[ny][nx] = temp;
		map[row][col] = 0;

		check[ny][nx] = false;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 3; i++) {
		fill_n(check[i], 3, false);
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				sp_y = i;
				sp_x = j;
			}
		}
	}

	check[sp_y][sp_x] = true;
	DFS(sp_y, sp_x, 0);

	if (ans == 987654321) {
		cout << -1 << '\n';
	}
	else {
		cout << ans << '\n';
	}

	return 0;
}