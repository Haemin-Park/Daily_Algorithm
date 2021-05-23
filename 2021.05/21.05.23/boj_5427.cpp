#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int w,h;
char arr[1000][1000];
int visit[1000][1000];
queue<pair<int,int>> q;
queue<pair<int,int>> f;

void bfs(){
	while(!q.empty()){
		if(!f.empty()){
			int fcnt=f.size();
			for(int i=1;i<=fcnt;i++){
				int fx=f.front().first;
				int fy=f.front().second;
				f.pop();
				for(int j=0;j<4;j++){
					int nfx=fx+dx[j];
					int nfy=fy+dy[j];

					if(arr[nfy][nfx]=='.'){
						arr[nfy][nfx]='*';
						f.push({nfx,nfy});
					}
				}
			} // 불 업데이트
		}
		
		int cnt = q.size();
		for(int i=1;i<=cnt;i++){
			
			int x=q.front().first;
			int y=q.front().second;
			q.pop();

			if(x==0 || x==(w-1) || y==0 || y==(h-1)){													cout<<visit[y][x]+1<<endl;
				return;
			}
			
			for(int i=0;i<4;i++){
				int nx=x+dx[i];
				int ny=y+dy[i];

				if(visit[ny][nx]==-1 && arr[ny][nx]=='.'){
					visit[ny][nx]=visit[y][x]+1;
					q.push({nx,ny});
				}
			}
		}
	}
	
	cout<<"IMPOSSIBLE"<<endl;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		q = {}; // 초기화
		f = {};
		
		cin>>w>>h;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				visit[i][j]=-1;
				cin>>arr[i][j];
				if(arr[i][j]=='@'){
					q.push({j,i});	
					visit[i][j]=0;
				}
				if(arr[i][j]=='*'){
					f.push({j,i});
				}
			}
		}
		bfs();
	}
}
