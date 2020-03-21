// 잠시 보류!
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, M,ans = 987654321;
char map[50][50];
bool check[50][50],temp_check[50][50];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
bool key[6] = { 0,0,0,0,0,0 };
vector<pair<int, int>> pos;
stack<int> prev_pos;

void DFS(int row, int col, int result) {
	if (map[row][col] == '1') {
		if (ans > result) {
			ans = result;
		}

		return;
	}

	int find_key = -1;

	if (map[row][col] >= 'a' && map[row][col] <= 'f') {
		find_key = map[row][col] - 'a';
		key[find_key] = true;
		map[row][col] = '.';

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				temp_check[i][j] = check[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				check[i][j] = true;
			}
		}

		// prev_pos.push(pos.size());
	}

	check[row][col] = true;

	cout << row << ' ' << col << '\n';
	for (int i = 0; i < 4; i++) {
		int ny = row + dir[i][0];
		int nx = col + dir[i][1];

		
		cout << "NEXT POS : " << ny << ' ' << nx << '\n';
		// 맵 경계를 벗어났을 경우
		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;

		// '#' 위치인 경우
		if (map[ny][nx] == '#')
			continue;

	
		// 문을 만났는데 열쇠를 소지하지 않았을 경우
		if (map[ny][nx] >= 'A' && map[ny][nx] <= 'F') {
			if (!key[map[ny][nx] - 'A'])
				continue;
		}
		
		// 이미 방문했던 칸인 경우
		if (check[ny][nx])
			continue;

		//pos.push_back({ ny,nx });
		DFS(ny, nx, result + 1);
		//pos.pop_back();

		cout << "현재 CUR : " << row << ' ' << col << '\n';
	}

	if (find_key != -1) {
		key[find_key] = false;
		map[row][col] = find_key + 'a';
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				check[i][j] = temp_check[i][j];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == '0')
				pos.push_back({ i,j });
		}
	}

	prev_pos.push(0);
	DFS(pos[0].first, pos[0].second, 0);

	if (ans == 987654321) {
		cout << -1 << '\n';
	}
	else {
		cout << ans << '\n';
	}

	return 0;
}