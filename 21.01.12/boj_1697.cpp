#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 200002
using namespace std;

int main() {
	int n, k;
	int dp[MAX];
	
	cin >> n >> k;

	fill(dp, dp + MAX, -1);

	dp[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		dp[i] = dp[i + 1] + 1;
	}

	for (int i = n + 1; i < MAX; i++) {
		dp[i] = dp[i - 1] + 1;
	}

	// 순간이동, 순간이동 전/후 저장
	for (int i = 1; i <= k; i++) {
		if (dp[i * 2 - 1] != -1)
			dp[i * 2 - 1] = min(dp[i * 2 - 1], dp[i] + 2);
		else
			dp[i * 2 - 1] = dp[i] + 2;
		
		if (dp[i * 2] != -1)
			dp[i * 2] = min(dp[i * 2], dp[i] + 1);
		else
			dp[i * 2] = dp[i] + 1;
		
		if (dp[i * 2 + 1] != -1)
			dp[i * 2 + 1] = min(dp[i * 2 + 1], dp[i] + 2);
		else
			dp[i * 2 + 1] = dp[i] + 2;
	}
	cout << dp[k];
}
