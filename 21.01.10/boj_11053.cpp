#include <iostream>
#include <algorithm>
using namespace std;

int a[1000], dp[1000] = {1,};

bool desec(int a, int b) {
	return a > b;
}

int main() {
	int n, input;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		a[i] = input;
	}

	for (int i = 1; i < n; i++) {
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) {
				if (max < dp[j])
					max = dp[j];
			}
		}
		dp[i] = max + 1;
	}
	sort(dp, dp + n, desec);
	cout << dp[0];
}
