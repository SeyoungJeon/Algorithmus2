#include <string>
#include <vector>
#include <iostream>

using namespace std;

int BS(vector<int> stones,int max_val,int k) {
	int left = 1,right = max_val,mid;
	int an = -1;

	while (left <= right) {
		mid = (left + right) / 2;
		
		int count = 0;
		bool possible = true;

		// �������� �ǳμ� ���� ���� ���� ����
		for (int i = 0; i < stones.size(); i++) {
			if (stones[i] - mid <= 0) {
				count++;
			}
			else {
				count = 0;
			}

			if (count >= k) {
				possible = false;
				break;
			}
		}

		// �����ϴٸ�
		if (possible) {
			left = mid + 1;
		}
		// �Ұ����ϴٸ�
		else {
			an = mid;
			right = mid - 1;
		}
	}

	return an;
}

int solution(vector<int> stones, int k) {
	int answer = 0, max_val = -1;

	// �ִ� ���ϱ�
	for (int i = 0; i < stones.size(); i++) {
		if (max_val < stones[i]) {
			max_val = stones[i];
		}
	}

	// �̺�Ž�� ����
	answer = BS(stones, max_val, k);

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solution({ 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 },3);

	return 0;
}