#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int arr[8][8];
int n, m;
bool visit[8][8] = { false };
int max_num;
vector <pair<int, int>> v;
queue < pair<int, int>> q;

void bfs() {
	
	int temp_arr[8][8];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			temp_arr[i][j] = arr[i][j];
	}
	
	queue <pair<int, int>> temp_q;

	temp_q = q;

	while (!temp_q.empty()) {
		int x = temp_q.front().first;
		int y = temp_q.front().second;

		temp_q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n)
				continue;

			if (!visit[ny][nx] && temp_arr[ny][nx] == 0) {
				visit[ny][nx] = true;
				temp_arr[ny][nx] = 2;
				temp_q.push(make_pair(nx, ny));
			}
		}
	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp_arr[i][j] == 0)
				cnt++;
		}
	}

	max_num = max(max_num, cnt);
}

void setting_wall(int x, int y, int n) {
	arr[y][x] = n;
}

int main() {
	
	int input;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input;
			arr[i][j] = input;
			if(input == 2) {
				q.push(make_pair(j, i));
				visit[i][j] = true;
			}
			if (input == 0)
				v.push_back(make_pair(j, i));
		}
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			for (int k = j + 1; k < v.size(); k++) {
				setting_wall(v[i].first, v[i].second, 1);
				setting_wall(v[j].first, v[j].second, 1);
				setting_wall(v[k].first, v[k].second, 1);
				bfs();
				setting_wall(v[i].first, v[i].second, 0);
				setting_wall(v[j].first, v[j].second, 0);
				setting_wall(v[k].first, v[k].second, 0);
				memset(visit, false, sizeof(visit));
			}
		}
	}

	cout << max_num;
}
