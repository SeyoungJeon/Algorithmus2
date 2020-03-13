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

	// �� �� ���� ����
	int cnt = 0;
	
	// ������
	q.push(a);
	check[a] = true;

	while (!q.empty()) {
		size_t q_size = q.size();
		
		for (size_t s = 0; s < q_size; s++) {
			int val = q.front();
			q.pop();

			// ������ ã�Ҵٸ�
			if (val == b) {
				find = true;
				break;
			}

			for (auto k : vec[val]) {
				// �湮�� ���ڴ� �ѱ��
				if (check[k])
					continue;

				check[k] = true;
				q.push(k);
			}
		}

		// �ٸ� ����� ã������ while�� ����
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

	// n �Է�
	cin >> n;

	// �̼� ����ؾ��ϴ� ���� �ٸ� �� ��� ��ȣ
	cin >> a >> b;

	// �θ� �ڽĵ鰣�� ������ ����
	cin >> m;

	for (int i = 0; i < m; i++) {
		int x, y;

		// �θ� x , �ڽ� y
		cin >> x >> y;

		vec[x].push_back(y);
		vec[y].push_back(x);
	}

	BFS();
	
	return 0;
}