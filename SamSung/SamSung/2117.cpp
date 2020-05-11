#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int CountHome(bool *map[],int y,int x,int N,int K) {
	int cnt = 0;

	for (int i = y - (K - 1); i <= y + (K - 1); i++) {
		// �� ��ȸ
		int dif = abs(i - y);
		int ny = i;

		for (int j = x - (K-dif-1); j < x - (K - dif - 1) + (K - dif) * 2 - 1 ; j++) {
			// �� ��ȸ
			int nx = j;

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;

			if (map[ny][nx])
				cnt++;
		}
	}

	return cnt;
}

int main() {
	int T;

	// �׽�Ʈ���̽� �Է�
	cin >> T;

	for (int test = 1; test <= T; test++) {
		int N, M,answer = -1;
		bool ** map;
		
		// N,M �Է� �ޱ�
		cin >> N >> M;

		// �� ���� ���� �Ҵ�
		map = new bool*[N];
		for (int i = 0; i < N; i++) {
			map[i] = new bool[N];
			fill_n(map[i], N, false);
		}

		// �� ���� �Է� �ޱ�
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		// K �� ��ȸ
		for (int K = 1; K <= 21; K++) {
			int cost = K * K + (K - 1)*(K - 1);

			// �� ��ȸ
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					int countHome = CountHome(map, i, j, N, K);
					int profit = countHome * M - cost;

					// ���ظ� ���� �ʾ��� ��
					if (profit >= 0) {
						if (answer < countHome) {
							answer = countHome;
						}
					}
				}
			}
		}

		// �� ���� ����
		for (int i = 0; i < N; i++) {
			delete[] map[i];
		}
		delete[] map;

		// ���� ���
		cout << "#" << test << ' ' << answer << '\n';
	}
}