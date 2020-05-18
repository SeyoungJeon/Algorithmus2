#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int d[100001], parent[100001], T, F;

int getParent(int num) {
	if (parent[num] == num)
		return num;
	return parent[num] = getParent(parent[num]);
}

int Union(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a == b)
		return d[a];

	parent[a] = b;
	d[b] += d[a];	// �� ������ ����� ������ ���Ѵ�.
	d[a] = 1;		// ����� ������ ����� ������ 1�� �ʱ�ȭ�Ѵ�.
	return d[b];	// �� ����� ���� ��ȯ
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++){
		fill_n(d, 100001, 1);
		for (int i = 0; i < 100001; i++) {
			parent[i] = i;
		}
		cin >> F;
		map<string, int> m;
		int cnt = 0;
		for (int j = 0; j < F; j++) {
			string a, b;
			cin >> a >> b;
			if (m[a] == 0) {
				m[a] = ++cnt;
			}
			if (m[b] == 0) {
				m[b] = ++cnt;
			}
			cout << Union(m[a], m[b]) << '\n';
		}
	}
	return 0;
}