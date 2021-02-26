#include <iostream>
#include <algorithm>
#define maxn 100001
using namespace std;

int arr[maxn], dp1[maxn], dp2[maxn];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp1[0] = arr[0];
	dp2[0] = arr[0];

	for (int i = 1; i < n; i++) {
		dp1[i] = max(dp1[i - 1] + arr[i], arr[i]);
		dp2[i] = max(dp1[i - 1], dp2[i - 1] + arr[i]);

	}

	sort(dp1, dp1 + n);
	sort(dp2, dp2 + n);

	if (dp1[n - 1] > dp2[n - 1])
		cout << dp1[n - 1];
	else
		cout << dp2[n - 1];
}
