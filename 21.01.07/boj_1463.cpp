#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

int main() {
	
	int num;
	
	cin >> num;
	
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	if (num > 3) {
		for (int i = 4; i <= num; i++) {
			if (i % 2 == 0 && i % 3 == 0) {
				dp[i] = 1 + min({ dp[i / 2],dp[i / 3],dp[i - 1] });
			}
			else if (i % 3 == 0) {
				dp[i] = 1 + min({ dp[i / 3], dp[i - 1] });
			}
			else if (i % 2 == 0) {
				dp[i] = 1 + min({dp[i / 2], dp[i - 1]});
			}
			else {
				dp[i] = 1 + dp[i - 1];
			}
		}
	}
	cout << dp[num];
}
