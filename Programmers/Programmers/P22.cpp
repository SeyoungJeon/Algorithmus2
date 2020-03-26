#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;

	priority_queue<int, vector<int>, less<int>> pq1;	// 내림차순
	priority_queue<int, vector<int>, greater<int>> pq2; // 오름차순

	int insert_count = 0, delete_count = 0;

	// 명령어 수행
	for (auto k : operations) {
		char operation = k.at(0);
		int num = stoi(k.substr(2));

		switch (operation)
		{
		case 'I':
			pq1.push(num);
			pq2.push(num);

			insert_count++;
			break;
		case 'D':
			if (insert_count == delete_count) {
				// 삭제할 값이 없다면
				continue;
			}
			else if (num == 1) {
				// 최댓값 삭제
				pq1.pop();
				delete_count++;
			}
			else if (num == -1) {
				// 최솟값 삭제
				pq2.pop();	
				delete_count++;
			}
			break;
		}

		// 삽입 횟수와 삭제횟수가 같다면 큐 비워주기
		if (insert_count == delete_count) {
			while (!pq1.empty()) {
				pq1.pop();
			}

			while (!pq2.empty()) {
				pq2.pop();
			}
		}
	}

	if (insert_count == delete_count) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		answer.push_back(pq1.top());
		answer.push_back(pq2.top());
	}

//	cout << answer[0] << ' ' << answer[1] << '\n';

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 실행 예시 1
//	solution({{ "I 16" }, { "D 1" }});

	// 실행 예시 2
	// solution({ {"I 7"},{"I 5"},{"I - 5"},{"D - 1"} });

	solution({ {"I 4"},{"I 3"},{"I 2"}, {"I 1"}, {"D 1"}, {"D 1"}, {"D -1"}, {"D -1"}, {"I 5"}, {"I 6"} });
	return 0;
}