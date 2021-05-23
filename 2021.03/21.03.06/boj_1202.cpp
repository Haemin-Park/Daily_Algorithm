#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

using ll=long long;

vector<pair<ll,ll>> arr;
vector<ll> c;
priority_queue<ll> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n, k;
	cin >> n >> k;
	ll m, v;
	for (int i = 0; i < n; i++) {
		cin >> m >> v;
		arr.push_back({ m,v });
	}
	ll in;
	for (int i = 0; i < k; i++) {
		cin >> in;
		c.push_back(in);
	}
	sort(arr.begin(), arr.end());
	sort(c.begin(), c.end());
	
	int index = 0;
	ll result = 0;
	for (int i = 0; i < k; i++) {
		for (int j = index; j < arr.size(); j++) {
			if (c[i] < arr[j].first) {
				break;
			}
			else{
				index = j + 1;
				pq.push(arr[j].second);
			}
		}
		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}
	cout << result;
}
