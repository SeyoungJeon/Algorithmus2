#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> arr) {
	int answer = 1;

	vector<int> v[101];
	
	for (int i = 0; i < arr.size(); i++) {
		int val = arr[i];
		for (int j = 2; j <= arr[i]; j++) {
			int cnt = 0;
			while (val % j == 0) {
				val /= j;
				cnt++;
			}
			if (cnt != 0) {
				if (!v[j].empty()) {
					if (v[j][0] < cnt) {
						v[j].pop_back();
						v[j].push_back(cnt);
					}
				}
				else {
					v[j].push_back(cnt);
				}
			}
		}
	}

	for (int i = 1; i <= 100; i++) {
		if(!v[i].empty()){
			int val = 1;
			for (int j = 0; j < v[i][0]; j++) {
				val *= i;
			}
			answer *= val;
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> arr;

	// 실행 예시 1
	arr.push_back(2);
	arr.push_back(6);
	arr.push_back(8);
	arr.push_back(14);

	// 실행 예시 2
	/*arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	*/
	
	cout << solution(arr) << '\n';

	return 0;
}