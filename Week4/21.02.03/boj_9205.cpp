#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n;
pair<int, int> f;
vector<tuple<int, int, bool>> c; // x, y, 방문여부
queue<tuple<int, int>> q; //x, y, 남은 맥주 수

void solution() {
	while (!q.empty()) {
		double x = get<0>(q.front());
		double y = get<1>(q.front());
		q.pop();

		if ((abs(f.first - x) + abs(f.second - y)) <= 1000) {
			cout << "happy\n";
			return;
		}

		for (int i = 0; i < c.size(); i++) {
			int cx = get<0>(c[i]);
			int cy = get<1>(c[i]);
			bool cvisit = get<2>(c[i]);
		
			if (!cvisit && (abs(cx - x) + abs(cy - y)) <= 1000) {
				q.push(make_tuple(cx, cy));
				c[i] = { cx,cy,true };
			}
		}
	}
	cout << "sad\n";
	return;
}

int main() {
	int t;
	cin >> t;
	int x, y;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cin >> x >> y;
		q = {};
		q.push(make_tuple(x, y));
		c.clear();
		for (int j = 0; j < n; j++) {
			cin >> x >> y;
			c.push_back(make_tuple(x, y, false));
		}
		cin >> x >> y;
		f = make_pair(x, y);

		solution();
	}
}
