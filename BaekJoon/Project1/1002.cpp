#include <iostream>
#include <math.h>

using namespace std;

int T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++) {
		double x1, y1, r1, x2, y2, r2, dif;
		
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		dif = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		
		if (x1 == x2 && y1 == y2 && r1 == r2) {
			cout << -1 << '\n';
		}
		else if (dif == r1 + r2 || dif == r1 - r2 || dif == r2 - r1) {
			cout << 1 << '\n';
		}
		else if (abs(r1-r2) < dif && dif < r1+r2) {
			cout << 2 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
	return 0;
}