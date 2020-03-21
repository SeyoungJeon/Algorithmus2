#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int solution(vector<vector<int>> triangle) {
	int answer = -1;
	int dp[500][500] = { 0 };

	dp[0][0] = triangle[0][0];
	cout << dp[0][0];
	for (int i = 0; i < triangle.size(); i++) {
		for (int j = 0; j < i * 2 ; j++) {
			if (i == 0) {
				continue;
			}

			if(j <= i )
				dp[i][j] = triangle[i][j];

			dp[i][j] += dp[i - 1][j/2];
//			cout << '\n' << i << "," << j << ' ' << idx << ' ' << dp[i][j] << '\n';
		//	dp[i][j] += triangle[i - 1][idx];
			cout << dp[i][j] << ' ';

			if (answer < dp[i][j]) {
				answer = dp[i][j];
			}
		}
		cout << '\n';
	}

	
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>> tri;

	tri.push_back({ 7 });
	tri.push_back({ 3,8 });
	tri.push_back({ 8,1,0 });
	tri.push_back({ 2,7,4,4 });
	tri.push_back({ 4,5,2,6,5 });

	solution(tri);

	return 0;
}