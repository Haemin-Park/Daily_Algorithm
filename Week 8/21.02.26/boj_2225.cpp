#include <iostream>
#define mod 1000000000
using namespace std;

long long dp[201][201]={0}; // dp[k][n]: k개의 숫자로 n을 만들수 있는 경우의 수

int main(){
	int n,k;
	cin>>n>>k;
	
	for(int i=0;i<=n;i++)
		dp[1][i]=1;
	
	for(int i=2;i<=k;i++){
		for(int j=0;j<=n;j++){
			int tmp=0;
			while(tmp<=j){
				dp[i][j]+=dp[i-1][tmp];
				tmp++;
			}
			dp[i][j]%=mod;
		}
	}
	
	cout<<dp[k][n];
}
