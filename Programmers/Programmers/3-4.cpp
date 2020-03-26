#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<pair<int, int>> k, l;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

void DFS() {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < k.size(); j++) {
			int ny = k[j].first + dir[i][0];
			int nx = k[j].second + dir[i][1];


		}
	}
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = true;
	
	
	// 자물쇠 비어진 곳
	for (int i = 0; i < lock.size(); i++) {
		for (int j = 0; j < lock[i].size(); j++) {
			if (lock[i][j] == 0) {
				l.push_back({ i,j });
			}
		}
	}
	
	// 열쇠 돌기 있는 부분
	for (int i = 0; i < key.size(); i++) {
		for (int j = 0; j < key[i].size(); j++) {
			if (key[i][j] == 1) {
				k.push_back({ i,j });
			}
		}
	}

	// 오른쪽으로 확인
	


	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	solution({ {0, 0, 0},{1, 0, 0},{0, 1, 1} }, { {1, 1, 1},{1, 1, 0},{1, 0, 1} });

	return 0;
}