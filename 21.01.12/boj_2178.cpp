#include <iostream>
#include <queue>
#define MAX 100
using namespace std;
int n, m;
char arr[MAX][MAX];
bool visit[MAX][MAX] = { false };
int dis[MAX][MAX] = { 0 };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	visit[sy][sx] = true;
	dis[sy][sx]++;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n)
				continue;

			if (!visit[ny][nx] && arr[ny][nx] == '1') {
				visit[ny][nx] = true;
				dis[ny][nx] = dis[y][x] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
	cout << dis[n - 1][m - 1];
}

int main() {
	cin >> n >> m;
	char c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			arr[i][j] = c;
		}
	}
	bfs(0, 0);
}
