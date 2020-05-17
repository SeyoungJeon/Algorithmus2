#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

struct Rotate {
	int r;
	int c;
	int s;
};

vector<Rotate> v;
int N, M, K, cp[51][51], r, c, s, answer = INT_MAX;
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
bool visit[6];

// 배열 최솟값 구하기
int GetValue() {
	int val = INT_MAX;
	for (int i = 1; i <= N; i++) {
		int temp = 0;
		for (int j = 1; j <= M; j++) {
			temp += cp[i][j];
		}
		if (val > temp)
			val = temp;
	}

	return val;
}

// 회전 연산
void RotateArray(int r,int c,int s) {
	while (s > 0) {
		int tempVal = cp[r - s][c - s];

		// 아래로 이동
		for (int i = r - s; i < r + s; i++) {
			cp[i][c - s] = cp[i + 1][c - s];
		}
	
		// 오른쪽으로 이동
		for (int j = c - s; j < c + s; j++) {
			cp[r + s][j] = cp[r + s][j + 1];
		}

		// 위로 이동
		for (int i = r + s; i > r - s; i--) {
			cp[i][c + s] = cp[i - 1][c + s];
		}

		// 왼쪽으로 이동
		for (int j = c + s; j > c - s + 1; j--) {
			cp[r - s][j] = cp[r - s][j - 1];
		}

		cp[r - s][c - s + 1] = tempVal;

		s--;
	}

}

// 순열 구하기
void DFS(int depth, int end) {
	if (depth >= end) {	
		int value = GetValue();
		if (answer > value)
			answer = value;

		return;
	}

	int temp[51][51];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			temp[i][j] = cp[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int next = i;

		if (visit[next])
			continue;

		visit[next] = true;
		RotateArray(v[i].r,v[i].c,v[i].s);
		DFS(depth + 1, end);
	
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cp[i][j] = temp[i][j];
			}
		}
		visit[next] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> cp[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		v.push_back({ r,c,s });
	}

	DFS(0, K);

	cout << answer << '\n';

	return 0;
}