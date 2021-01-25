#include <iostream>
#define mod 1000000000
using namespace std;

int dp[101][10]={0};
// dp[a][b]=c : b로 끝나는 a 자릿수의 계단수는 c
int main(){
	int n;
	cin>>n;
	
	for(int i=1;i<=9;i++)
		dp[1][i]=1;
	
	for(int i=2;i<=n;i++){
		for(int j=0;j<=9;j++){
			if(j==0)
				dp[i][j]=dp[i-1][1];
			else if(j==9)
				dp[i][j]=dp[i-1][8];
			else{
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
			}
			dp[i][j]%=mod;
		}
	}
	
	long long sum=0;
	for(int i=0;i<=9;i++)
		sum+=dp[n][i];
	
	cout<<sum%mod;
}
