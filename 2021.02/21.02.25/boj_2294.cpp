#include <iostream>
#include <algorithm>
#define maxn 10002
using namespace std;

int dp[10001];
int main(){
	fill(dp,dp+10002,10002);
	int arr[101];
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	dp[0]=0;
	
	for(int i=0;i<n;i++){
		for(int j=1;j<=k;j++){
			if(j>=arr[i]){
				dp[j]=min(dp[j],dp[j-arr[i]]+1);
			}
		}
	}
	if(dp[k]==maxn)
		cout<<-1;
	else
		cout<<dp[k];
}
