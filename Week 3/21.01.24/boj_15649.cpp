#include <iostream>
#define MAX 9
using namespace std;

int n,m;
int arr[MAX];
bool visit[MAX];

void solution(int cnt){
	if(cnt==m){
		for(int i=0;i<m;i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
	}
	else{
		for(int i=1;i<=n;i++){
			if(!visit[i]){
				visit[i]=true;
				arr[cnt]=i;
				solution(cnt+1);
				visit[i]=false;
			}
		}
	}
}

int main(){
	cin>>n>>m;
	solution(0);
}
