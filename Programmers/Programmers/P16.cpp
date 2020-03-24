#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

multimap<string,string> m;

bool solution(vector<string> phone_book) {
	bool answer = true;

	// 자동 정렬 되어서 삽입됨
	for (auto k : phone_book) {
		m.insert({ k,"1" });
	}

	string previous;
	// 2번쨰 원소부터 순회
	for (auto iter = m.begin() ; iter != m.end() ; iter++) {
		// 첫 번째 원소를 이전 변수에 넣기
		if (iter == m.begin()) {
			previous = (*iter).first;
			continue;
		}

		// 접두어 비교
		string compare = (*iter).first;
		if (previous == compare.substr(0, previous.size())) {
			answer = false; 
			break;
		}
		previous = compare;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<string> phone_book;
	/*phone_book.push_back("119");
	phone_book.push_back("97674223");
	phone_book.push_back("1195524421");


	


	phone_book.push_back("12");
	phone_book.push_back("123");
	phone_book.push_back("1235");
	phone_book.push_back("567");
	phone_book.push_back("88");*/
	phone_book.push_back("123");
	phone_book.push_back("456");
	phone_book.push_back("789");
	cout << solution(phone_book) << '\n';
	return 0;
}