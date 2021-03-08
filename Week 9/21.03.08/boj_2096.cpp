#include <iostream>
#include <algorithm>
#include <cstring>
#define maxn 100000
using namespace std;

int arr[maxn][3] = { 0 };
int dp[3] = { 0 };

int main() {
	int n;
	int maxs, mins;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 2; j++) {
			cin >> arr[i][j];
		}
	}
	
	dp[0] = arr[0][0]; dp[1] = arr[0][1]; dp[2] = arr[0][2];
	for (int i = 1; i < n; i++) {
		int tmp0, tmp1, tmp2;
		tmp0 = max(dp[0],dp[1]) + arr[i][0];
		tmp1 = max({ dp[0],dp[1],dp[2] }) + arr[i][1];
		tmp2 = max(dp[1], dp[2]) + arr[i][2];
		dp[0] = tmp0;
		dp[1] = tmp1;
		dp[2] = tmp2;
	}
	maxs = *max_element(dp, dp + 3);

	dp[0] = arr[0][0]; dp[1] = arr[0][1]; dp[2] = arr[0][2];
	for (int i = 1; i < n; i++) {
		int tmp0, tmp1, tmp2;
		tmp0 = min(dp[0], dp[1]) + arr[i][0];
		tmp1 = min({ dp[0],dp[1],dp[2] }) + arr[i][1];
		tmp2 = min(dp[1], dp[2]) + arr[i][2];
		dp[0] = tmp0;
		dp[1] = tmp1;
		dp[2] = tmp2;
	}
	mins = *min_element(dp, dp + 3);

	cout << maxs << " " << mins;
}
