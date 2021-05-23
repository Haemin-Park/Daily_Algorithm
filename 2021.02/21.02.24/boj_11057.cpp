#include <iostream>
#define mod 10007
using namespace std;

 int dp[1001][10]; // dp[a][b]: a번째 숫자가 b일때 오름수

 int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;
	for (int i = 1; i <= n; i++)
		dp[i][0] = 1;

 	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 9; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			dp[i][j] %= mod;
		}
	}

 	long long sum = 0;
	for (int j = 0; j <= 9; j++) {
		sum += dp[n][j];
		sum %= mod;
	}
	cout << sum;
}
