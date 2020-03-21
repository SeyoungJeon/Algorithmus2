#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, a, b, m;
vector<int> vec[101];
bool check[101] = {false};

void BFS() {
	queue<int> q;
	bool find = false;

	// 촌 수 세는 변수
	int cnt = 0;
	
	// 시작점
	q.push(a);
	check[a] = true;

	while (!q.empty()) {
		size_t q_size = q.size();
		
		for (size_t s = 0; s < q_size; s++) {
			int val = q.front();
			q.pop();

			// 상대방을 찾았다면
			if (val == b) {
				find = true;
				break;
			}

			for (auto k : vec[val]) {
				// 방문한 숫자는 넘기기
				if (check[k])
					continue;

				check[k] = true;
				q.push(k);
			}
		}

		// 다른 사람을 찾았으면 while문 종료
		if (find)
			break;

		cnt++;
	}

	if (find)
		cout << cnt << '\n';
	else
		cout << -1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// n 입력
	cin >> n;

	// 촌수 계산해야하는 서로 다른 두 사람 번호
	cin >> a >> b;

	// 부모 자식들간의 관계의 개수
	cin >> m;

	for (int i = 0; i < m; i++) {
		int x, y;

		// 부모 x , 자식 y
		cin >> x >> y;

		vec[x].push_back(y);
		vec[y].push_back(x);
	}

	BFS();
	
	return 0;
}