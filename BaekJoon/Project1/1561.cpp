#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>

using namespace std;

long long N,answer;
int M;
vector<long long> arr;

long long BS() {
	// �ִ� ũ�� 2000000000 * 30 ����
	long long left = 1, right = 60000000000, mid,sum;
	long long result = -1;
	while (left <= right) {
		mid = (left + right) / 2;
		
		// �ش� �ð��� ���� ����� ���ϱ�
		sum = M;
		for (int i = 1; i <= M; i++) {
			sum += (mid / arr[i]);
		}

		// ���� ������� N�� �۰ų� ������
		if (sum >= N) {
			result = mid;	// �ð� ����
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// N,M �Է� �ޱ�
	cin >> N >> M;

	// M �迭 ũ�� �Ҵ�
	arr.resize(M + 1);

	// �迭 ���� �Է� �ޱ�
	for (int i = 1; i <= M; i++) {
		cin >> arr[i];
	}
	
	// ������� ���̱ⱸ ���� ���� ���
	if (N <= M) {
		cout << N << '\n';
		return 0;
	}

	// ����Ž��
	long long time = BS();
	long long sum = M;

	// ���� �ð����� ���� ��� ���ϱ�
	for (int i = 1; i <= M; i++) {
		sum += (time - 1) / arr[i];
	}

	// �ش� �ð��� ���°�� Ÿ���� ���ϱ�
	for (int i = 1; i <= M; i++) {
		if (time % arr[i] == 0) {
			sum++;
		}

		if (sum == N) {
			cout << i << '\n';
			break;
		}
	}

	return 0;
}