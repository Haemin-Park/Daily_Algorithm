#include <iostream>
#include <string>
#define mod 1000000
using namespace std;

int dp[2][5001];

int main() {
	string s;
	cin >> s;
	bool isSuc = true;

	if (s[0] == '0') {
		isSuc = false;
	}
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == '0' && (s[i - 1] != '1' && s[i - 1] != '2')) {
			isSuc = false;
			break;
		}
	}

	if (isSuc) {
		dp[0][0] = 1;

		dp[0][1] = 1;
		dp[1][1] = 0;
		for (int i = 2; i <= s.size(); i++) {
			if (s[i - 1] != '0') {
				dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]);
				if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
					dp[1][i] = (dp[0][i - 2] + dp[1][i - 2]);
				}
			}
			else {
				dp[1][i] = (dp[0][i - 2] + dp[1][i - 2]);
			}

			dp[0][i] %= mod;
			dp[1][i] %= mod;
		}
		cout << (dp[0][s.size()] + dp[1][s.size()]) % mod;
	}
	else {
		cout << 0;
	}
}
