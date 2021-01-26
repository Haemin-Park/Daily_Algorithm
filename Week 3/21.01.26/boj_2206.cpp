#include <iostream>
#include <queue>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
char arr[1000][1000];
bool visit[1000][1000][2]={false};
queue<pair<pair<int,int>,pair<int,int>>> q;
int n,m;

int bfs(){
	
	q.push(make_pair(make_pair(0,0),make_pair(0,1))); // ((x, y),(벽을 부순 횟수, 거리))
	
	while(!q.empty()){
		int x=q.front().first.first;
		int y=q.front().first.second;
		int wc=q.front().second.first;
		int dis=q.front().second.second;
		q.pop();
		
		if(x==m-1&&y==n-1)
			return dis;
		
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(nx<0||nx>=m||ny<0||ny>=n)
				continue;
			
			if(!visit[ny][nx][wc]&&arr[ny][nx]=='1'){
				if(wc==1)
					continue;
				else{
					visit[ny][nx][wc]=true;
					q.push(make_pair(make_pair(nx,ny),make_pair(1,dis+1)));
				}
			}
			if(!visit[ny][nx][wc]&&arr[ny][nx]=='0'){
				visit[ny][nx][wc]=true;
				q.push(make_pair(make_pair(nx,ny),make_pair(wc,dis+1)));
			}
		}
	}
	
	return -1;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m;
	
	char c;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>c;
			arr[i][j]=c;
		}
	}
	
	int dis=bfs();
	
	cout<<dis;
	
}
