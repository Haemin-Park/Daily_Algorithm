#include <iostream>
#include <cstring>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int t, m, n, k;
int arr[50][50] = {0,};
bool visit[50][50] = { false, };

void dfs(int x, int y) {

	visit[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= m || ny >= n)
			continue;
		
		if (!visit[ny][nx] && arr[ny][nx] == 1) {
			dfs(nx, ny);
		}
	}
}

int main() {
	int x, y, result;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> m >> n >> k;

		result = 0;
		memset(arr, 0, sizeof(arr));
		memset(visit, false, sizeof(visit));

		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			arr[y][x] = 1;
		}

		for (int yi = 0; yi < n; yi++) {
			for (int xi = 0; xi < m; xi++) {
				if (!visit[yi][xi] && arr[yi][xi] == 1) {
					result++;
					dfs(xi, yi);
				}
			}
		}

		cout << result << endl;
	}
}
