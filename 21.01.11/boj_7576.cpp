#include <iostream>
#include <queue>
using namespace std;

int m, n, input;
int tomato[1000][1000];
bool visit[1000][1000] = { false };
int day[1000][1000] = { -1, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

queue<pair<int, int>> q;

int last_day = 0;

void bfs() {

	last_day = 0;

	while (!q.empty()) {
		pair<int, int> xy = q.front();
		int x = xy.first;
		int y = xy.second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n)
				continue;
			if (!visit[ny][nx] && tomato[ny][nx] == 0) {
				q.push(make_pair(nx, ny));
				visit[ny][nx] = true;
				tomato[y][x] = 1;
				day[ny][nx] = day[y][x] + 1;
				last_day = day[ny][nx];
			}
		}
	}
	bool isAllVisit = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j] && tomato[i][j] == 0)
				isAllVisit = false;
		}
	}
	if (isAllVisit)
		cout << last_day;
	else
		cout << -1;
}

int main() {

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input;
			tomato[i][j] = input;
			if (input == 1) {
				q.push(make_pair(j, i));
				visit[i][j] = true;
				day[i][j] = 0;
			}
		}
	}
	bfs();
}
