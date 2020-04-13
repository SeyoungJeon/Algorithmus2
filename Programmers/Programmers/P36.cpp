#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> st;


	for (auto pos : moves) {
		for (int i = 0 ; i < board[pos-1].size() ; i++) {
			if (board[i][pos-1] == 0)
				continue;
			
			if (st.empty()){
				st.push(board[i][pos-1]);
			}
			else {
				if (st.top() == board[i][pos-1]) {
					answer += 2;
					st.pop();
				}
				else {
					st.push(board[i][pos-1]);
				}
			}	

			board[i][pos-1] = 0;

			break;
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solution({ {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} }, { 1,5,3,5,1,2,1,4 });
	return 0;
}