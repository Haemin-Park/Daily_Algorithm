#include <iostream>
using namespace std;
int m,n;
int arr[501][501];
int dp[501][501];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int dfs(int x, int y){
	if(x==n-1&&y==m-1){
		return 1;
	}
	if(dp[y][x]!=-1){
		return dp[y][x];
	}
	
	dp[y][x]=0;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		if(nx<0||nx>=n||ny<0||ny>=m)
			continue;
		
		if(arr[y][x]>arr[ny][nx]){
			dp[y][x]+=dfs(nx,ny);
		}
	}
	return dp[y][x];
}

int main(){
	cin>>m>>n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
			dp[i][j]=-1;
		}
	}
	cout<<dfs(0,0);	
}
