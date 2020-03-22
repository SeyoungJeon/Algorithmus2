#include <iostream>
#include <vector>

using namespace std;

int n, percent[4] , dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
vector<pair<int, int>> map;
vector<int> m;
double cal = 0;

// �ش� ��ġ�� �湮 ����
bool IsVisit(int row, int col) {
	for (int i = 0; i < map.size(); i++) {
		if (map[i].first == row && map[i].second == col)
			return true;
	}

	return false;
}

void DFS(int depth,int row, int col) {
	if (depth == n) {
		double temp = 1;

		// �� ���� ����� �� Ȯ�� ���
		for (auto k : m) {
			temp *= (double)percent[k] / 100.0;
		}
		cal += temp;
		
		return;
	}

	// ��Ʈ��ŷ
	for (int i = 0; i < 4; i++) {
		int ny = row + dir[i][0];
		int nx = col + dir[i][1];

		if (IsVisit(ny,nx))
			continue;

		m.push_back(i);
		map.push_back({ ny,nx });
		DFS(depth + 1,ny,nx);
		map.pop_back();
		m.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// �κ� �ൿ ���� �Է� �ޱ�
	cin >> n;

	// �� ���� Ȯ�� �Է� �ޱ�
	for (int i = 0; i < 4; i++) {
		cin >> percent[i];
	}

	// �ʱ� �湮 ����
	map.push_back({ 0,0 });

	// Ž��
	DFS(0,0,0);

	// �Ҽ��� 9�ڸ����� ��� ����
	cout.precision(9);

	// ���� ���
	cout << cal << '\n';

	return 0;
}