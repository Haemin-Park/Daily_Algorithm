#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
char arr[100][100];
bool visit[100][100] = { false };
int result1, result2;
queue<pair<int, int>> q;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (!visit[ny][nx] && arr[y][x] == arr[ny][nx]) {
				q.push(make_pair(nx, ny));
				visit[ny][nx] = true;
			}
		}
	}
}

int main() {

	cin >> n;
	char c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			arr[i][j] = c;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				q.push(make_pair(j, i));
				visit[i][j] = true;
				bfs();
				result1++;
			}
		}
	}
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j]=='G') {
				arr[i][j] = 'R';
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				q.push(make_pair(j, i));
				visit[i][j] = true;
				bfs();
				result2++;
			}
		}
	}

	cout << result1 << " " << result2;
}
