#include <iostream>
#include <queue>
#include <cstring>
#define maxn 101
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int h,w;
int arr[maxn][maxn]={0};
bool visit[maxn][maxn]={false};
queue<pair<int,int>> q;
queue<pair<int,int>> melt;

void bfs(){
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(nx<0||nx>=w||ny<0||ny>=h)
				continue;
			
			if(arr[ny][nx]==1)
				melt.push(make_pair(nx,ny));
			
			if(!visit[ny][nx] && arr[ny][nx]==0){
				q.push(make_pair(nx,ny));
				visit[ny][nx]=true;
			}
		}
	}
	
	while(!melt.empty()){
		int x=melt.front().first;
		int y=melt.front().second;
		melt.pop();
		arr[y][x]=0;
	}
}

int main(){
	cin>>h>>w;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>arr[i][j];
		}
	}
	
	int time=0;
	int result=0;
	int cnt=0;

	while(1){
		memset(visit,false,sizeof(visit));
		cnt=0;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(arr[i][j]==1){
					cnt++;
				}
			}
		}
		if(cnt==0)
			break;
		q.push(make_pair(0,0));
		visit[0][0]=true;
		bfs();
		time++;
		result=cnt;

	}
	cout<<time<<"\n"<<result;
}
