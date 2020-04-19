#include <iostream>
#include <vector>

#define	N 1
#define S 2
#define E 3
#define W 4

using namespace std;

struct Shark{
	int id; // id
	int y;	// y좌표
	int x;	// x좌표
	int s;	// 속도
	int d;	// 방향
	int z;	// 크기
	bool exist;
};

Shark *shark;
int R, C, M , answer = 0;
int **map;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 격자수칸 상어 수 입력 받기
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
		// 1번 오른쪽으로 이동
		humanPos++;

		// 2번 땅과 제일 가까운 상어 잡기
		for (int j = 1; j <= R; j++) {
			if (map[j][humanPos] != -1) {
				int sharkId = map[j][humanPos];
				answer += shark[sharkId].z;
				shark[sharkId].exist = false;
				map[j][humanPos] = -1;
				break;
			}
		}

		// 3번 이동
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

		// 겹치는 위치가 있는지 확인 
		for (int j = 0; j < temp.size(); j++) {
			int id = temp[j].id;
			int y = temp[j].y;
			int x = temp[j].x;
			int s = temp[j].s;
			int d = temp[j].d;
			int size = temp[j].z;
			bool exist = temp[j].exist;

			if (tempMap[y][x] == -1) {
				// 겹치지 않을 경우
				tempMap[y][x] = id;
				shark[id] = { id,y,x,s,d,size, exist };
			}
			else {
				// 겹치는 경우
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
		
		// 임시 맵 원래 맵에 복사
		for (int j = 0; j <= R; j++) {
			for (int k = 0; k <= C; k++) {
				map[j][k] = tempMap[j][k];
			}
		}
		
		// 임시 맵 동적할당 해제
		for (int j = 0; j <= R; j++) {
			delete[] tempMap[j];
		}
	}

	// 답 출력
	cout << answer << '\n';

	return 0;
}