#include <iostream>
#include <cstring>
using namespace std;

int arr[21];
int dp[10001];
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		int n,m;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		cin>>m;
		dp[0]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(j<arr[i])
					continue;
				dp[j]+=dp[j-arr[i]];
			}
		}
		cout<<dp[m]<<"\n";
	}
}
