#include <iostream>
#include <vector>

using namespace std;

int input[10];
bool *check;
vector<vector<int>> v;
vector<pair<int, int>> *map;
int answer = -1;


void DFS(int depth, vector<int> k) {
	if (depth >= 10) {
		pair<bool, pair<int, int>> pos[5];
		bool possible = true;

		// 초기화
		for (int i = 0; i < 5; i++) {
			pos[i].first = true;
			pos[i].second.first = 0;
			pos[i].second.second = 0;
		}

		int val = 0;

		for (int i = 0; i < 10; i++) {
			int turn = k[i];
			int cnt = input[i];
			int curPos = pos[turn].second.first;
			bool fast = false;
		
			if (curPos == 5 || curPos == 10 || curPos == 15) {
				fast = true;
			}

			while (cnt > 0) {
				if (map[pos[turn].second.first].size() == 2 && !fast) {
					pos[turn].second.first = map[pos[turn].second.first][1].first;
				}
				else {
					pos[turn].second.first = map[pos[turn].second.first][0].first;
				}

				if (pos[turn].second.first == 0) {
					break;
				}

				cnt--;
			}

			val += map[pos[turn].second.first][0].second;

			for (int j = 1; j < 5; j++) {
				if (pos[j].second.first == pos[turn].second.first 
					&& pos[turn].second.first != 0 && turn != j) {
					possible = false;
					break;
				}
			}
		}

		// 겹치는 경우 제외
		if (!possible)
			return;

		if (answer < val) {
			answer = val;
		}

		return; 
	}

	for (int i = 1; i <= 4; i++) {
		check[depth] = true;
		k.push_back(i);
		DFS(depth + 1, k);
		k.pop_back();
		check[depth] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	map = new vector<pair<int, int>>[33];
	map[0].push_back({ 1,0 }); //
	map[1].push_back({ 2,2 }); //
	map[2].push_back({ 3,4 }); //
	map[3].push_back({ 4,6 }); //
	map[4].push_back({ 5,8 }); //
	map[5].push_back({ 21,10 }); // 파랑색
	map[5].push_back({ 6,10 }); //
	map[6].push_back({ 7,12 }); //
	map[7].push_back({ 8,14 }); //
	map[8].push_back({ 9,16 }); // 
	map[9].push_back({ 10,18 }); //
	map[10].push_back({ 29,20 }); //
	map[10].push_back({ 11,20 }); //
	map[11].push_back({ 12,22 }); //
	map[12].push_back({ 13,24 });
	map[13].push_back({ 14,26 });
	map[14].push_back({ 15,28 });
	map[15].push_back({ 27,30 });
	map[15].push_back({ 16,30 });
	map[16].push_back({ 17,32 });
	map[17].push_back({ 18,34 });
	map[18].push_back({ 19,36 });
	map[19].push_back({ 20,38 });
	map[20].push_back({ 32,40 });
	map[21].push_back({ 22,13 });
	map[22].push_back({ 23,16 });
	map[23].push_back({ 24,19 });
	map[24].push_back({ 30,25 });
	map[25].push_back({ 24,26 });
	map[26].push_back({ 25,27 });
	map[27].push_back({ 26,28 });
	map[28].push_back({ 24,24 });
	map[29].push_back({ 28,22 });
	map[30].push_back({ 31,30 });
	map[31].push_back({ 20,35 });
	map[32].push_back({ 0,0 });

	check = new bool[10];
	fill_n(check, 10, false);

	for (int i = 0; i < 10; i++) {
		cin >> input[i];
	}

	vector<int> temp;
	DFS(0, temp);

	cout << answer << '\n';

	return 0;
}