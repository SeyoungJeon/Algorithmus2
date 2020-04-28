#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> m;

// Union-find로 해결하기
long long find(long long u) {
	if (m[u] == 0) {
		return u;
	} 
	return m[u] = find(m[u]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;

	for (auto num : room_number) {
		long long key = find(num);
		answer.push_back(key);
		m[key] = key + 1;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solution(10, { 1,1,1,1,1,1 });

	return 0;
}