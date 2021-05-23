#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int s, t;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		cin >> s >> t;
		v.push_back({ s,t });
	}
	sort(v.begin(), v.end());
	
	priority_queue<int> endt;
	endt.push(0);
	for (int i = 0; i < v.size(); i++) {
		if (-1 * endt.top() <= v[i].first) {
			endt.pop();
			endt.push(-1 * v[i].second);
		}
		else {
			endt.push(-1 * v[i].second);
		}
	}
	cout << endt.size();
}
