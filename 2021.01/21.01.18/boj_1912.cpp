#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, input;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
	}

	vector<int> dp(n);
	dp[0] = v[0];
	for (int i = 1; i < v.size(); i++) {
		dp[i] = max(v[i], dp[i - 1] + v[i]);
	}
	sort(dp.begin(), dp.end());
	cout << dp[n - 1];
}
