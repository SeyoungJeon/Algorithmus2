#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// row ดย 0 ~ 9 , c ดย 0 ~ 8
int s_r, s_c;
int k_r, k_c;
int ans = 987654321;
int dir[8][2] = { {-3,-2}, {-3,2} , {-2,-3} ,{2,-3} ,{3,-2} ,{3,2} , {-2,3} , {2,3} };
int check[8][2] = { {-2,-1}, {-2,1} ,{-1,-2} ,{1,-2} , {2,-1} ,{2,1} ,{-1,2} , {1,2} };
queue<pair<int, int>> q;

int BFS() {
	int result = 0;
	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			int cur_r = q.front().first;
			int cur_c = q.front().second;

			q.pop();

			if (cur_r == k_r && cur_c == k_c) {
				return result;
			}

			for (int j = 0; j < 8; j++) {
				bool exist = false;

				int ny = cur_r + dir[j][0];
				int nx = cur_c + dir[j][1];

				if (dir[j][0] == -3 && cur_r - 1 == k_r && cur_c == k_c)
					exist = true;
				else if (dir[j][0] == 3 && cur_r + 1 == k_r && cur_c == k_c)
					exist = true;
				else if (dir[j][1] == -3 && cur_r == k_r && cur_c - 1 == k_c)
					exist = true;
				else if (dir[j][1] == 3 && cur_r == k_r && cur_c + 1 == k_c)
					exist = true;

				if (cur_r + check[j][0] == k_r && cur_c + check[j][1] == k_c)
					exist = true;
				
				if (ny < 0 || ny >= 10 || nx < 0 || nx >= 9 || exist)
					continue;

				q.push({ ny,nx });
			}
		}

		result++;
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s_r >> s_c;
	cin >> k_r >> k_c;

	q.push({ s_r,s_c });

	ans = BFS();

	cout << ans << '\n';

	return 0;
}