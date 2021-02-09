#include <iostream>
using namespace std;

int v[500000];
bool iscycle=false;

int find(int x){
	if(x==v[x]) return x;
	else return v[x]=find(v[x]);
}

void merge(int u, int h){
	u=find(u);
	h=find(h);
	if(u!=h){
		v[u]=h;
	}else{
		iscycle=true;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		v[i]=i;
	}
	
	int i1,i2;
	
	int result=0;
	for(int i=0;i<m;i++){
		cin>>i1>>i2;
		if(!iscycle){
			merge(i1,i2);
			result=i+1;	
		}
	}
	
	if(iscycle)
		cout<<result;
	else
		cout<<0;
	
}
