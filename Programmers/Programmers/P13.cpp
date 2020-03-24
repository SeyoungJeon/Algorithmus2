#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	for (auto k : commands) {
		int start = k[0] - 1;
		int end = k[1] - 1;
		int elem = k[2] - 1;

		vector<int> temp;
		
		for (int i = start; i <= end; i++) {
			temp.push_back(array[i]);
		}

		sort(temp.begin(), temp.end());
		
		
		for (auto m : temp) {
			cout << m << ' ';
		}
		cout << '\n';

		answer.push_back(temp[elem]);
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> array;
	vector<vector<int>> commands;

	array.push_back(1);
	array.push_back(5);
	array.push_back(2);
	array.push_back(6);
	array.push_back(3);
	array.push_back(7);
	array.push_back(4);

	commands.push_back({ 2,5,3 });
	commands.push_back({ 4,4,1 });
	commands.push_back({ 1,7,3 });

	solution(array, commands);

	return 0;
}