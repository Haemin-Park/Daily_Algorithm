#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define maxn 10001
#define init 2000000000
using namespace std;
int n,m,c1,c2;
vector<pair<int,int>> v[maxn];
bool visit[maxn]={false}, check;
int maxc=0, result=0, cost=0;

void dfs(int start){
	
	visit[start]=true;
	
	if(start==c2){
		result=result>cost?result:cost;
		check=true;
		return;
	}
	for(int i=0;i<v[start].size();i++){
		pair<int,int> next=v[start][i];
		if(!visit[next.first]&&next.second>=cost){
			dfs(next.first);
		}
	}
}

void bs(){
	int left=0;
	int right=maxc;

	while(left<=right){
		memset(visit,false,sizeof(visit));
		check=false;
		
		int mid=(left+right)/2;
		cost=mid;
		
		dfs(c1);
		if(check){
			left=mid+1;
		}
		else{
			right=mid-1;
		}
	}
	cout<<result;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	int i1,i2,i3;
	for(int i=0;i<m;i++){
		cin>>i1>>i2>>i3;
		v[i1].push_back({i2,i3});
		v[i2].push_back({i1,i3});
		maxc=maxc>i3?maxc:i3;
		
	}
	cin>>c1>>c2;
	bs();
}
