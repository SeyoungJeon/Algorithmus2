#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> check;
bool *visit, possible;

bool compare(const vector<string> &a, const vector<string> &b) {
	if (a[0] < b[0]) {
		return true;
	}
	else if (a[0] == b[0]) {
		if (a[1] < b[1])
			return true;
		else
			return false;
	}
	else {
		return false;
	}
}

void DFS(int depth, int pos, string cur, vector<vector<string>> tickets) {

	if (depth == tickets.size() - 1) {
		check.push_back(tickets[pos][1]);
		possible = true;
		
		return;
	}
	
	for (int i = 0; i < tickets.size(); i++) {
		
		string cur_end = tickets[pos][1];
		string next_start = tickets[i][0];

		// �������� �������� �ٸ��ٸ�
		if (cur_end != next_start)
			continue;

		// ����ߴ� ���Ҷ��
		if (visit[i])
			continue;

		// �� Ʈ��ŷ
		visit[pos] = true;
		check.push_back(next_start);
		DFS(depth + 1, i, next_start, tickets);
		
		// �����θ� ã�Ҵٸ�
		if (possible)
			return;

		check.pop_back();
		visit[pos] = false;

		
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;

	sort(tickets.begin(), tickets.end(), compare);
	visit = new bool[tickets.size()];
	fill_n(visit, tickets.size(), 0);

	for (int i = 0; i < tickets.size(); i++) {
		if (tickets[i][0] == "ICN") {
			// ���� �ʱ�ȭ
			fill_n(visit, tickets.size(), false);
			check.clear();
			possible = false;

			// ó�� ������ �湮 ǥ�� �� �߰�
			visit[i] = true;
			check.push_back("ICN");

			
			DFS(0, i, tickets[i][0], tickets);
		}

		if (possible)
			break;
	}

	return check;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<string>> tickets;

	tickets.push_back({"ICN","SFO"});
	tickets.push_back({ "ICN","ATL" });
	tickets.push_back({ "ICN","ATL" });
	tickets.push_back({ "SFO","WBE" });
	tickets.push_back({ "SFO","ATL" });
	tickets.push_back({ "ATL","ICN" });
	tickets.push_back({ "ATL","SFO" });
	
	/*tickets.push_back({ "ICN","JFK" });
	tickets.push_back({ "HND","IAD" });
	tickets.push_back({ "JFK","HND" });*/

	solution(tickets);

	return 0;
}