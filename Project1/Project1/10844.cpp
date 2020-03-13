#include <iostream>
#include <set>
#include <string>

using namespace std;

int N, cnt = 0;

void DFS(int depth, int val) {
	if (depth == N - 1) {
		cnt++;
		return;
	}

	if (val < 9){
		DFS(depth + 1, val + 1);
	}

	if (val > 0){
		DFS(depth + 1, val - 1);
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= 9; i++) {
		DFS(0, i);
	}
	
	cout << cnt % 1000000000 << '\n';
	
	return 0;
}