#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 25

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
char arr[MAX][MAX];
bool visit[MAX][MAX]={false};
int cnt=0;
vector<int> h;
queue<pair<int,int>> q;
int n;

void bfs(){
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(nx<0||nx>=n||ny<0||ny>=n)
				continue;
			
			if(!visit[ny][nx] && arr[ny][nx]=='1'){
				q.push(make_pair(nx,ny));
				visit[ny][nx]=true;
				cnt++;
			}
		}
	}	
}

int main(){
	
	cin>>n;
	
	char input;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>input;
			arr[i][j]=input;
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!visit[i][j] && arr[i][j]=='1'){
				q.push(make_pair(j,i));
				visit[i][j]=true;
				cnt++;
				bfs();
				h.push_back(cnt);
				cnt=0;
			}
		}
	}
	
	cout<<h.size()<<"\n";
	sort(h.begin(),h.end());
	for(int v:h)
		cout<<v<<"\n";
}
