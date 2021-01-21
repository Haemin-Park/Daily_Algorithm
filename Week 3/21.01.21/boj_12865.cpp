#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int arr[101][2] = { 0 };
int dp[101][100001] = { 0 };

int main() {
	cin >> n >> k;
	int i1, i2;
	for (int i = 1; i <= n; i++) {
		cin >> i1 >> i2;
		arr[i][0] = i1;
		arr[i][1] = i2;
	}
	// dp[a][b] = c -> a번 물건까지만 고려 && 견딜 수 있는 무게를 b라고 가정시 최대 총 가치
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			int w = arr[i][0];
			int v = arr[i][1];

			if (w > j) { // i번 물건의 무게가 견딜 수 있다고 가정하는 무게 j보다 클 때
				dp[i][j] = dp[i - 1][j]; // 이전(i-1번) 최대 총 가치
			}
			else {
				dp[i][j] = max(dp[i - 1][j], v + dp[i - 1][j - w]);
				// 이전(i-1번) 최대 총 가치, i번 물건을 선택했을 때의 총 가치 중 큰 것을 선택
			}
		}
	}
	cout << dp[n][k];
}
