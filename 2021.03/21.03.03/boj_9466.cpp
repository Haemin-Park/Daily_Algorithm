#include <iostream>
#include <cstring>
#define maxn 100001
using namespace std;

int arr[maxn];
bool visit[maxn]={false};
bool done[maxn]={false}; // 방문이 끝난 노드
int cnt=0;

void dfs(int x){
	visit[x]=true;
	if(!visit[arr[x]]){
		dfs(arr[x]);
	}else if(!done[arr[x]]){ // 다음 노드가 방문한 노드이고, 방문이 끝나지 않은 노드라면 -> 사이클 형성
		for(int i=arr[x]; i!=x; i=arr[i]){
			cnt++;
		}
		cnt++;
	}
	done[x]=true; // 방문 끝
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin>>t;
	while(t){
		int n;
		cnt=0;
		t--;
		cin>>n;
		memset(visit,false,sizeof(visit));
		memset(done,false,sizeof(done));
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		for(int i=1;i<=n;i++){
			if(!visit[i]){
				dfs(i);
			}
		}
		cout<<n-cnt<<endl;
	}
}
