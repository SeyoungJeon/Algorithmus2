#include <iostream>

using namespace std;

int N, cnt = 0;
bool *col, *l, *r;

void DFS(int row) {
	// ��� ���� ��ȸ���� ���
	if (row == N) {
		cnt++;
		return;
	}

	for (int i = 0; i < N; i++) {
		
		// ��, ���� �밢��, ������ �밢�� ���� ���� �Ǵ�
		if (col[i] || l[row+i] || r[N-(i-row+1)])
			continue;

		// ��Ʈ��ŷ
		col[i] = l[row + i] = r[N - (i - row + 1)] = true;
		DFS(row + 1);
		col[i] = l[row + i] = r[N - (i - row + 1)] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// N*N ü����, ���ǰ��� �Է� �ޱ�
	cin >> N;
	
	// �迭 ���� �ʱ�ȭ
	col = new bool[N];
	l = new bool[2*N-1];
	r = new bool[2*N-1];
	fill_n(col, N, false);
	fill_n(l, 2 * N - 1, false);
	fill_n(r, 2 * N - 1, false);

	// ��� 0���� Ž��
	DFS(0);

	// ���� ���
	cout << cnt << '\n';

	return 0;
}