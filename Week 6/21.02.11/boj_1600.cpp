#include <iostream>
#include <tuple>
#include <algorithm>
#include <queue>
#define init 2000000000
#define maxn 201
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int hx[8]={2,2,1,1,-1,-1,-2,-2};
int hy[8]={1,-1,2,-2,2,-2,1,-1};
int k,w,h,result=init;
int arr[maxn][maxn];
int check[maxn][maxn][maxn]={0};
queue<tuple<int,int,int,int>> q;

void bfs(){
	while(!q.empty()){
		int x=get<0>(q.front());
		int y=get<1>(q.front());
		int jump=get<2>(q.front());
		int move=get<3>(q.front());
		q.pop();
		
		if(x==w-1&&y==h-1){
			result=min(result,move);
			return;
		}
		else{
			
			for(int i=0;i<4;i++){
				int nx=x+dx[i];
				int ny=y+dy[i];
				
				if(nx<0||nx>=w||ny<0||ny>=h)
					continue;
				
				if(arr[ny][nx]==0&&(check[ny][nx][jump]==0)||check[ny][nx][jump]>move+1){
					check[ny][nx][jump]=move+1;
					q.push({nx,ny,jump,move+1});
				}
			}
			
			if(jump<k){
				for(int i=0;i<8;i++){
					int nx=x+hx[i];
					int ny=y+hy[i];
					
					if(nx<0||nx>=w||ny<0||ny>=h)
						continue;
					
					if(arr[ny][nx]==0&&(check[ny][nx][jump+1]==0)||check[ny][nx][jump+1]>move+1){
						check[ny][nx][jump+1]=move+1;
						q.push({nx,ny,jump+1,move+1});
					}					
				}				
			}

		}
	}
}

int main(){
	cin>>k;
	cin>>w>>h;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>arr[i][j];
		}
	}
	
	q.push({0,0,0,0});
	check[0][0][0]=0;
	bfs();
	
	if(result==init)
		cout<<-1;
	else
		cout<<result;
}
