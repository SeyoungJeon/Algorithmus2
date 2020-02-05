#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

char map[100][100];
bool check[100][100];
int T, h, w,ans=0;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

set<char> key;
string keys;

void DFS(int row,int col) {
	check[row][col] = true;

	if (map[row][col] >= 'A' && map[row][col] <= 'Z') {
		bool find = false;
		for (auto iter = key.begin(); iter != key.end(); iter++) {
			if ((*iter) - 'a' == map[row][col] - 'A') {
				find = true;
				break;
			}
		}

		if (find) {
			map[row][col] = '.';
		}
		else {
			return;
		}
	}

	if (map[row][col] >= 'a' && map[row][col] <= 'z') {
		key.insert(map[row][col]);
		map[row][col] = '.';
	}

	if (map[row][col] == '$') {
		map[row][col] = '.';
		ans++;
	}

	for (int i = 0; i < 4; i++) {
		int ny = row + dir[i][0];
		int nx = col + dir[i][1];

		if (ny < 0 || ny >= h || nx < 0 || nx >= w)
			continue;

		if (map[ny][nx] == '*' || check[ny][nx])
			continue;

		DFS(ny, nx);
	}
}

void func(vector<pair<int,int>> entrance) {
	while(true){
		char temp_map[100][100];
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				temp_map[i][j] = map[i][j];
			}
		}

		for(auto k : entrance){
			for (int i = 0; i < h; i++) {
				fill_n(check[i], w, false);
			}

			DFS(k.first, k.second);
		}

		bool change = false;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] != temp_map[i][j]) {
					change = true;
				}
			}
		}

		if (!change)
			break;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> h >> w;
		vector<pair<int, int>> entrance;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
				if ((i == 0 || j == 0 || i == h - 1 || j == w - 1) && map[i][j] != '*') {
					entrance.push_back({ i,j });
				}
			}
		}

		
		cin >> keys;

		for (int i = 0; i < keys.size(); i++) {
			if (keys[i] == '0')
				break;

			key.insert(keys[i]);
		}

		if(entrance.size() != 0)
			func(entrance);

		cout << "´ä : ";
		cout << ans << '\n';

				
		ans = 0;

		key.clear();
	}
	
	return 0;
}