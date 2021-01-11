#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> x, pair<int,int> y) {
	if (x.second == y.second)
		return x.first < y.first;
	else
		return x.second < y.second;
}

int main() {
	vector<pair<int, int>> t;
	int n, input1, input2, endt = 0,cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input1 >> input2;
		t.push_back(make_pair(input1, input2));
	}

	sort(t.begin(), t.end(), compare);

	for (int i = 0; i < n; i++) {
		if (endt <= t[i].first) {
			cnt++;
			endt = t[i].second;
		}
	}

	cout << cnt;
}
