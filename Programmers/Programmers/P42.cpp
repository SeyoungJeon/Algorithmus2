#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

string ChangeItoS(int time) {
	string h = to_string(time / 60);
	string m = to_string(time % 60);

	if ((time / 60) < 10)
		h = "0" + h;

	if ((time % 60) < 10)
		m = "0" + m;

	return h + ":" + m;
}

int ChangeStoI(string time) {
	int h = stoi(time.substr(0, 2));
	int m = stoi(time.substr(3, 2));

	return h * 60 + m;
}

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	int minute = 540;
	deque<string> table(timetable.begin(), timetable.end());

	sort(table.begin(), table.end());

	int lastVal = -1;
	for (int i = 0; i < n; i++) {
		int count = 0;
		while (!table.empty()) {
			int curMinute = ChangeStoI(table.front());
			if (minute >= curMinute && count < m) {
				lastVal = curMinute;
				table.pop_front();
			}
			else {
				break;
			}

			count++;
		}

		if (count < m) {
			answer = ChangeItoS(minute);
		}
		else {
			answer = ChangeItoS(lastVal - 1);
		}
		
		minute += t;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solution(1, 1, 5, {"08:00","08:01","08:02","08:03"});
	solution(2, 10, 2, {"09:10","09:09","08:00"});
	solution(2, 1, 2, {"09:00","09:00","09:00","09:00"});
	solution(1, 1, 5, {"00:01","00:01","00:01","00:01","00:01"});
	solution(1, 1, 1, {"23:59"});
	solution(10, 60, 45, { "23:59" ,"23:59" ,"23:59" ,
		"23:59" ,"23:59" ,"23:59" ,
		"23:59" ,"23:59" ,"23:59" ,
		"23:59" ,"23:59" ,"23:59" ,
		"23:59" ,"23:59" ,"23:59" ,
		"23:59" });
		
	return 0;
}