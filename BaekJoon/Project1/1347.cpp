#include <iostream>
#include <set>
#include <string>
#include <math.h>

#define U 1
#define R 2
#define D 3
#define L 4

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int len;
	string input;

	cin >> len;
	cin >> input;

	pair<int, int> row, col,user;
	row.first = 0; row.second = 0;
	col.first = 0; col.second = 0;
	user.first = 0; user.second = 0;

	int userDir = D;

	set<pair<int, int>> pos;
	pos.insert({ 0,0 });
	for (int i = 0; i < len; i++) {
		switch (input[i]) {
		case 'F':
			switch (userDir) {
			case U:
				user.first--;
				break;
			case R:
				user.second++;
				break;
			case D:
				user.first++;
				break;
			case L:
				user.second--;
				break;
			}
			pos.insert(user);
			break;
		case 'L':
			userDir -= 1;
			if (userDir == 0)
				userDir = L;
			break;
		case 'R':
			userDir += 1;
			if (userDir == 5)
				userDir = U;
			break;
		}


		if (user.first < row.first) {
			row.first = user.first;
		}
		if(user.first > row.second) {
			row.second = user.first;
		}
		if (user.second < col.first) {
			col.first = user.second;
		}
		if (user.second > col.second) {
			col.second = user.second;
		}
	}

	int N = abs(row.first - row.second) + 1;
	int M = abs(col.first - col.second) + 1;

	bool **m;
	m = new bool*[N];
	for (int i = 0; i < N; i++) {
		m[i] = new bool[M];
		fill_n(m[i], M, false);
	}

	for (auto p : pos) {
		int y = p.first + abs(row.first), x = p.second + abs(col.first);
		m[y][x] = true;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (m[i][j])
				cout << '.';
			else
				cout << '#';
		}
		cout << '\n';
	}
	
	return 0;
}