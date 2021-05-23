#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int w, h;
int dx[8] = { 1,-1,0,0,1,-1,1,-1 };
int dy[8] = { 0,0,1,-1,1,-1,-1,1 };
int arr[50][50];
bool visit[50][50] = { false };
queue<pair<int, int>> q;
int cnt = 0;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		visit[y][x] = true;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= w || ny < 0 || ny >= h)
				continue;

			if (!visit[ny][nx] && arr[ny][nx] == 1) {
				visit[ny][nx] = true;
				q.push(make_pair(nx, ny));
			}

		}
			
	}
}

int main() {

	int input;

	while (cin >> w >> h) {
		if (w == 0 && h == 0)
			return 0;
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> input;
				arr[i][j] = input;
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visit[i][j] && arr[i][j] == 1) {
					q.push(make_pair(j, i));
					bfs();
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		memset(visit, false, sizeof(visit));
		memset(arr, 0, sizeof(arr));
		cnt = 0;
	}
}
