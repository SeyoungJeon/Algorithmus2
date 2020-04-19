#include <iostream>
#include <vector>

#define	N 1
#define S 2
#define E 3
#define W 4

using namespace std;

struct Shark{
	int id; // id
	int y;	// y��ǥ
	int x;	// x��ǥ
	int s;	// �ӵ�
	int d;	// ����
	int z;	// ũ��
	bool exist;
};

Shark *shark;
int R, C, M , answer = 0;
int **map;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// ���ڼ�ĭ ��� �� �Է� �ޱ�
	cin >> R >> C >> M;

	map = new int*[R + 1];
	for (int i = 0; i <= R; i++) {
		map[i] = new int[C + 1];
		fill_n(map[i], C + 1, -1);
	}

	shark = new Shark[M + 1];

	int cnt = 1;
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		shark[cnt] = { cnt,r,c,s,d,z,true };
		map[r][c] = cnt;
		cnt++;
	}

	int humanPos = 0;
	
	for (int i = 0; i < C; i++) {
		// 1�� ���������� �̵�
		humanPos++;

		// 2�� ���� ���� ����� ��� ���
		for (int j = 1; j <= R; j++) {
			if (map[j][humanPos] != -1) {
				int sharkId = map[j][humanPos];
				answer += shark[sharkId].z;
				shark[sharkId].exist = false;
				map[j][humanPos] = -1;
				break;
			}
		}

		// 3�� �̵�
		vector<Shark> temp;
		for (int j = 1; j <= M; j++) {
			if (shark[j].exist) {
				int id = shark[j].id;
				int curY = shark[j].y;
				int curX = shark[j].x;
				int dir = shark[j].d;
				int fast = shark[j].s;
				int size = shark[j].z;
				bool exist = shark[j].exist;

				int m, n;

				if (dir == N || dir == S) {
					m = fast / (R*2-2);
					n = fast % (R*2-2);
				}
				else {
					m = fast / (C*2-2);
					n = fast % (C*2-2);
				}
	
				for (int k = 0; k < n; k++) {
					switch (dir)
					{
					case N:
						curY--;
						break;
					case E:
						curX++;
						break;
					case S:
						curY++;
						break;
					case W:
						curX--;
						break;
					}

					if (curY < 1) {
						curY += 2;
						dir = S;
					}else if (curY > R) {
						curY -= 2;
						dir = N;
					}
					else if (curX < 1) {
						curX += 2;
						dir = E;
					}
					else if (curX > C) {
						curX -= 2;
						dir = W;
					}

				}

				temp.push_back({ id,curY,curX,fast,dir, size ,exist });
			}
		}

		int **tempMap;
		tempMap = new int*[R + 1];
		for (int i = 0; i <= R; i++) {
			tempMap[i] = new int[C + 1];
			fill_n(tempMap[i], C + 1, -1);
		}

		// ��ġ�� ��ġ�� �ִ��� Ȯ�� 
		for (int j = 0; j < temp.size(); j++) {
			int id = temp[j].id;
			int y = temp[j].y;
			int x = temp[j].x;
			int s = temp[j].s;
			int d = temp[j].d;
			int size = temp[j].z;
			bool exist = temp[j].exist;

			if (tempMap[y][x] == -1) {
				// ��ġ�� ���� ���
				tempMap[y][x] = id;
				shark[id] = { id,y,x,s,d,size, exist };
			}
			else {
				// ��ġ�� ���
				int prevId = tempMap[y][x];
				if (shark[prevId].z < size) {
					shark[prevId].exist = false;
					tempMap[y][x] = id;
					shark[id] = { id,y,x,s,d,size, exist };
				}
				else {
					shark[id].exist = false;
				}
			}
		}
		
		// �ӽ� �� ���� �ʿ� ����
		for (int j = 0; j <= R; j++) {
			for (int k = 0; k <= C; k++) {
				map[j][k] = tempMap[j][k];
			}
		}
		
		// �ӽ� �� �����Ҵ� ����
		for (int j = 0; j <= R; j++) {
			delete[] tempMap[j];
		}
	}

	// �� ���
	cout << answer << '\n';

	return 0;
}