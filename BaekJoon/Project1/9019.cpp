#include <iostream>
#include <vector>
#include <queue>
#include <string>

#define D 1
#define S 2
#define L 3
#define R 4

using namespace std;

struct Data {
	int val;
	string command;
};

int T;
int cur, des;
vector<vector<char>> ans;
bool check[10000];

int Command_D(int n) {
	return (n * 2) % 10000;
}

int Command_S(int n) {
	if (n == 0)
		return 9999;
	else
		return n - 1;
}

int Command_Dir(int n, int dir) {
	int d1 = n / 1000;
	int d2 = (n % 1000) / 100;
	int d3 = ((n % 1000) % 100) / 10;
	int d4 = ((n % 1000) % 100) % 10;

	int change = 0;
	if (dir == L) {
		change = ((d2 * 10 + d3) * 10 + d4) * 10 + d1;
	}
	else {
		change = ((d4 * 10 + d1) * 10 + d2) * 10 + d3;
	}

	return change;
}

void BFS() {
	queue<Data> q;
	string command = "";
	Data data;
	data.val = cur;
	data.command = command;

	check[cur] = true;
	q.push(data);

	while (!q.empty()) {
		int cur = q.front().val;
		string command = q.front().command;

		q.pop();

		if (cur == des) {
			cout << command << '\n';
			break;
		}

		for (int i = 1; i <= 4; i++) {
			int n_val = -1;
			switch (i) {

			case D:
				n_val = Command_D(cur);
				command += "D";
				break;
			case S:
				n_val = Command_S(cur);
				command += "S";
				break;
			case L:
				n_val = Command_Dir(cur, L);
				command += "L";
				break;
			case R:
				n_val = Command_Dir(cur, R);
				command += "R";
				break;
			}

			if (check[n_val]) {
				command.pop_back();
				continue;
			}

			check[n_val] = true;
			q.push({ n_val,command });
			command.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		vector<char> v;
		fill_n(check, 10000, false);

		cin >> cur >> des;

		BFS();
	}

	return 0;
}