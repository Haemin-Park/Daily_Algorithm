#include <stdio.h>
#include <queue>
#include <vector>
#define MAX_V 20001
#define INF 1e9
using namespace std;

int vn, en, k;
vector<pair<int, int>> adj[MAX_V]; // (정점번호, 가중치)
vector<int> dist(MAX_V, INF);

//우선순위 큐를 이용하는 방법(O(|E|log|V|))
void dijkstra(int start) {
	dist[start] = 0;
	
	//	 (-정점까지의 거리, 정점번호)
	//	 priority_queue는 기본적으로 가장 큰 원소가 위로가도록 큐를 구성한다.
	//	 가장 작은 거리를 구해야하므로 거리의 부호를 바꾼다.

	priority_queue<pair<int, int>> pq;

	pq.push(make_pair(dist[start], start));

	while (!pq.empty()) {
		int x = pq.top().second;
		int x_cost = -pq.top().first;
		pq.pop();
		
		if (dist[x] < x_cost) continue;

		for (int i = 0; i < adj[x].size(); i++) {
			int next = adj[x][i].first;
			int next_dist = x_cost + adj[x][i].second;
			
			if (dist[next] > next_dist) {
				dist[next] = next_dist;
				pq.push(make_pair(-next_dist, next));
			}
		}
	}
}

int main() {
	
	int v1, v2, w;

	scanf("%d %d", &vn, &en);
	scanf("%d", &k);

	for (int i = 0; i < en; i++) {
		scanf("%d %d %d", &v1, &v2, &w);
		adj[v1].push_back(make_pair(v2, w));
	}

	dijkstra(k);

	for (int i = 1; i <= vn; i++) {
		if (dist[i] != INF)
			printf("%d\n", dist[i]);
		else
			printf("INF\n");
	}
}
