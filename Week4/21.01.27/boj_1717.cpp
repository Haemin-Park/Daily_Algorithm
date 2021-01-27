#include <iostream>
using namespace std;

int parent[1000001];

int find(int x){
	if(parent[x]==x) return x;
	return parent[x]=find(parent[x]);
}

void merge(int u, int v){
	u=find(u);
	v=find(v);
	if(u!=v) parent[u]=v;
}

int main(){
	int n,m;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m;
	
	for(int i=0;i<=n;i++)
		parent[i]=i;
	
	int i1,o,i2;
	
	for(int i=0;i<m;i++){
		cin>>o>>i1>>i2;
		if(o==0){
			merge(i1,i2);
		}
		else if(o==1){
			if(find(i1)==find(i2))
				cout<<"YES"<<"\n";
			else
				cout<<"NO"<<"\n";
		}
	}
}
