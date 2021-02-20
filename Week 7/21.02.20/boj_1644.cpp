#include <iostream>
using namespace std;

bool isNotPrime[4000001]={false};

int main(){
	int n;
	cin>>n;
	for(int i=2;i*i<=n;i++){
		if(!isNotPrime[i]) // 소수이면
		{
			for(int j=i*i;j<=n;j+=i)
				isNotPrime[j]=true;
		}
	}
	int index=2,cnt=0;
	while(index<=n){
		int sum=0;
		for(int i=index;i<=n;i++){
			if(!isNotPrime[i]){
				if(sum+i==n){
					cnt++;
					break;
				}
				else if(sum+i>n){
					break;
				}
				else{
					sum+=i;
				}
			}
		}
		while(isNotPrime[++index]){}
	}
	cout<<cnt;
}
