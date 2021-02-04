#include <iostream>
#include <queue>
#include <tuple>
#define maxn 51
using namespace std;
int n,m;
int head[4]={0,1,2,3}; // 북, 동, 남, 서
int dx[4]={-1,0,1,0}; // 바라보는 방향에 따른 왼쪽 상대좌표
int dy[4]={0,-1,0,1};
int arr[maxn][maxn];
bool visit[maxn][maxn]={false};
queue<tuple<int,int,int>> q;
int cnt=0;
void bfs(){
	while(!q.empty()){
		int x=get<0>(q.front());
		int y=get<1>(q.front());
		int d=get<2>(q.front());
		q.pop();
		
		bool back=true;
		for(int i=0;i<4;i++){
			int fx=x+dx[i];
			int fy=y+dy[i];
			if(!visit[fy][fx] && arr[fy][fx]==0)
				back=false;
		}
		
		if(back){
			int bx=x,by=y;
			switch(d){
				case 0: by+=1; 
					break;
				case 1:	bx-=1; 
					break;
				case 2: by-=1; 
					break;
				case 3: bx+=1; 
			}
			if(arr[by][bx]==1){
				return;
			}
			else{
				q.push(make_tuple(bx,by,d));
			}
		}else{
			for(int i=0;i<4;i++){
				if(d==head[i]){
					int nx=x+dx[i];
					int ny=y+dy[i];
					int nd=(d+3)%4;

					if(!visit[ny][nx] && arr[ny][nx]==0){
						q.push(make_tuple(nx,ny,nd));
						visit[ny][nx]=true;
						cnt++;
					}else{
						q.push(make_tuple(x,y,nd));
					}
					break;
				}
			}	
		}
	}
}

int main(){
	cin>>n>>m; // 세로, 가로
	
	int x,y,d;
	cin>>y>>x>>d;
	q.push(make_tuple(x,y,d));
	visit[y][x]=true;
	cnt++;
	
	int input;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>input;
			arr[i][j]=input;
		}
	}
	bfs();
	cout<<cnt;
}
