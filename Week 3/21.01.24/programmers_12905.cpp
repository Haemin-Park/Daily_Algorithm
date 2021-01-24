#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int dp[1000][1000]={0};
    
    int col=board.size(); // board.size(): 행 개수
    int row=board[0].size(); // board[0].size(): 열 개수
    
    for(int i=0;i<col;i++){ 
        dp[i][0]=board[i][0];
        answer=max(answer,dp[i][0]);
    }
    
    for(int i=0;i<row;i++){
        dp[0][i]=board[0][i];
        answer=max(answer,dp[0][i]);
    }
    
    for(int i=1;i<col;i++){
        for(int j=1;j<row;j++){
            if(board[i][j]==1){
                dp[i][j]=min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
                answer=max(answer,dp[i][j]);
            }
        }
    }

    return answer*answer;
}
