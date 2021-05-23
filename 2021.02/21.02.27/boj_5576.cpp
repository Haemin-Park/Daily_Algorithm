#include <iostream>
#define mod 9901
using namespace std;

long long dp[100001][3]; // 0: 사자 x, 1: 왼쪽에 사자, 2: 오른쪽에 사자

int main(){
	int n;
	cin>>n;
	
	dp[1][0]=1; dp[1][1]=1; dp[1][2]=1;
	for(int i=2;i<=n;i++){
		dp[i][0]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%mod;
		dp[i][1]=(dp[i-1][0]+dp[i-1][2])%mod;
		dp[i][2]=(dp[i-1][0]+dp[i-1][1])%mod;
	}
	
	cout<<(dp[n][0]+dp[n][1]+dp[n][2])%mod;
}
