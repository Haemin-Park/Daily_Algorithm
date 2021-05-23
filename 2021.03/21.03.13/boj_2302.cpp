#include <iostream>
using namespace std;

int dp[41][2] = { 0 };

int main() {
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = -1; dp[i][1] = -1;
	}
	dp[1][0] = 1; dp[1][1] = 0; dp[2][1] = 1;
	int input;
	for (int i = 1; i <= m; i++) {
		cin >> input;
		dp[input][1] = 0;
		if(input != n)
			dp[input + 1][1] = 0;
	}
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		if (dp[i][1] == -1)
			dp[i][1] = dp[i - 2][0] + dp[i - 2][1];
	}
	cout << dp[n][0] + dp[n][1];
}
