#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dh[2] = { 1,-1 };
int n, m, height;
int arr[100][100][100];
int visit[100][100][100] = { false };
int day[100][100][100] = { 0 };
int lastday = 0;
queue<tuple<int, int, int>> q; // x, y, h
void bfs() {

	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int h = get<2>(q.front());
		q.pop();
		visit[h][y][x] = true;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || nx >= m || ny < 0 || ny >= n)
				continue;

			if (!visit[h][ny][nx] && arr[h][ny][nx] == 0) {
				visit[h][ny][nx] = true;
				arr[h][ny][nx] = 1;
				day[h][ny][nx] = day[h][y][x] + 1;
				lastday = day[h][ny][nx];
				q.push(make_tuple(nx, ny, h));
			}

		}
	
		for (int i = 0; i < 2; i++) {
			int nh = h + dh[i];
			
			if (nh < 0 || nh >= height)
				continue;
			
			if (!visit[nh][y][x] && arr[nh][y][x] == 0) {
				visit[nh][y][x] = true;
				arr[nh][y][x] = 1;
				day[nh][y][x] = day[h][y][x] + 1;
				lastday = day[nh][y][x];
				q.push(make_tuple(x, y, nh));
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input;

	cin >> m >> n >> height;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> input;
				arr[i][j][k] = input;
				if (input == 1)
					q.push(make_tuple(k, j, i));
			}
		}
	}

	bfs();

	bool isAllOk = true;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (arr[i][j][k] == 0) {
					isAllOk = false;
					break;
				}
			}
		}
	}

	if (isAllOk)
		cout << lastday;
	else
		cout << -1;
}
