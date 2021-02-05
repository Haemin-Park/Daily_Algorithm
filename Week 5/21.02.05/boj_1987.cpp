#include <iostream>
#include <algorithm>
#define maxn 21
using namespace std;

int r,c; // 세로, 가로
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
char arr[maxn][maxn];
bool visit[maxn][maxn]={false};
bool check[150]={false};
int result=0;

void dfs(int x, int y, int cnt){
	result=max(result, cnt);
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];

		if(nx<0||nx>=c||ny<0||ny>=r)
			continue;

		if(!visit[ny][nx] && !check[arr[ny][nx]]){
			check[arr[ny][nx]]=true;
			visit[y][x]=true;
			dfs(nx,ny,cnt+1);
			check[arr[ny][nx]]=false;
			visit[y][x]=false;
		}
	}
}

int main(){	
	cin>>r>>c;
	char input;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>input;
			arr[i][j]=input;
		}
	}
	check[arr[0][0]]=true;
	visit[0][0]=true;
	dfs(0,0,1);
	cout<<result;
}
