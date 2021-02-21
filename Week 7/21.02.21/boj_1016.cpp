#include <iostream>
using namespace std;

bool isJegop[1000001]={false};	
int cnt=0;
long long minn,maxn;

int main(){
	cin>>minn>>maxn;
	
	for(long long i=2;i*i<=maxn;i++){
		long long n=minn/(i*i);
		
		if(minn%(i*i)>0) n++;
		
		for(long long j=i*i*n;j<=maxn;j+=i*i){
			isJegop[j-minn]=true;
		}
		
	}
	
	for(int i=0;i<=maxn-minn;i++){
		if(!isJegop[i]) cnt++;
	}
	
	cout<<cnt;
}
