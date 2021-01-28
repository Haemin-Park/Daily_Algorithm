#include <iostream>
#include <vector>
using namespace std;

int n,m, i1, i2;
vector<int> v[101];
int result=-1;

void dfs(int cnt, int before, int start){

	for(int i=0;i<v[start].size();i++){
		int next=v[start][i];
		
		if(next==i2){
			result=cnt+1;
			return ;
		}
		else if(next!=before){
			dfs(cnt+1,start,next);
		}
		
	}
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;

	cin>>i1>>i2;
	
	cin>>m;
	
	int x,y;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	dfs(0,0,i1);
	
	cout<<result;
	
}
