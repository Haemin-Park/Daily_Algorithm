#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

int dz[3] = { 1,-1 };
int dx[4] = { 1,-1,0,0};
int dy[4] = { 0,0,1,-1};
char b[31][31][31];
int dis[31][31][31] = { 0 };
bool visit[31][31][31] = { false };
queue<tuple<int, int, int>> q;
bool isSuc = false;
int endx, endy, endz;
int l, r, c;

void bfs() {
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int z = get<2>(q.front());
		q.pop();

		if (x == endx && y == endy && z == endz) {
			isSuc = true;
			return;
		}

		for (int i = 0; i < 2; i++) {
			int nz = z + dz[i];
			
			if (nz < 0 || nz >= l)
				continue;

			if (!visit[nz][y][x] && b[nz][y][x] != '#') {
				visit[nz][y][x] = true;
				dis[nz][y][x] = dis[z][y][x] + 1;
				q.push({ x,y,nz });
			}

		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= c || ny < 0 || ny >= r )
				continue;

			if (!visit[z][ny][nx] && b[z][ny][nx] != '#') {
				visit[z][ny][nx] = true;
				dis[z][ny][nx] = dis[z][y][x] + 1;
				q.push({ nx,ny,z });
			}
		}
	}
}

int main() {
	while (1) {
		cin >> l >> r >> c;
		if (!l && !r && !c)
			break;
		isSuc = false;
		memset(dis, 0, sizeof(dis));
		memset(visit, false, sizeof(visit));
		q = {};
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> b[i][j][k];
					if (b[i][j][k] == 'S') {
						visit[i][j][k] = true;
						q.push({ k,j,i });
					}
					if (b[i][j][k] == 'E') {
						endx = k; endy = j; endz = i;
					}
				}
			}
		}
		bfs();
		if (isSuc) {
			cout << "Escaped in " << dis[endz][endy][endx] << " minute(s)." << endl;
		}
		else {
			cout << "Trapped!" << endl;
		}
	}
}
