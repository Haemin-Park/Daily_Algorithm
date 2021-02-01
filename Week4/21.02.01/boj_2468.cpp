#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int arr[101][101];
bool visit[101][101];
queue<pair<int,int>> q;

void bfs(int h){
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(nx<0||nx>=n||ny<0||ny>=n)
				continue;
			
			if(!visit[ny][nx] && arr[ny][nx]>h){
				q.push(make_pair(nx,ny));
				visit[ny][nx]=true;
			}
		}
	}
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int input,minh=101,maxh=0;
	
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>input;
			arr[i][j]=input;
			minh=min(input,minh);
			maxh=max(input,maxh);
		}
	}
	
	int result=1,cnt=0;
	int s=minh;
	while(s<maxh){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(!visit[i][j] && arr[i][j]>s){
					q.push(make_pair(j,i));
					visit[i][j]=true;
					bfs(s);
					cnt++;
				}
			}
		}
		result=max(cnt,result);
		cnt=0;
		memset(visit,false,sizeof(visit));
		s++;
	}
	
	cout<<result;
}
