#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

multimap<string,string> m;

bool solution(vector<string> phone_book) {
	bool answer = true;

	// �ڵ� ���� �Ǿ ���Ե�
	for (auto k : phone_book) {
		m.insert({ k,"1" });
	}

	string previous;
	// 2���� ���Һ��� ��ȸ
	for (auto iter = m.begin() ; iter != m.end() ; iter++) {
		// ù ��° ���Ҹ� ���� ������ �ֱ�
		if (iter == m.begin()) {
			previous = (*iter).first;
			continue;
		}

		// ���ξ� ��
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