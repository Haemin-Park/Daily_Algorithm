#include <iostream>
#include <algorithm>
using namespace std;

pair<int,int> arr[101];
int dp[101][10001]={0};

int main(){
	int t,k,p,n;
	cin>>t;
	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>p>>n;
		arr[i].first=p;
		arr[i].second=n;
	}
	
	sort(arr+1,arr+k+1);
	
	for(int i=1;i<=k;i++)
		dp[i][0]=1;
	
	for(int i=1;i<=k;i++){
		int price=arr[i].first;
		int cnt=arr[i].second;
		for(int j=1;j<=t;j++){
			if(price>j){
				dp[i][j]=dp[i-1][j];
				continue;
			}
			if(j<price*(cnt+1))
				dp[i][j]+=dp[i-1][j]+dp[i][j-price];
			else{
				int c=0;
				while(c<=cnt){
					dp[i][j]+=dp[i-1][j-price*c];
					c++;
				}
			}
		}
	}
	
	cout<<dp[k][t];
}
