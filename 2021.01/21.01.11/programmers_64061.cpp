#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    
    for(int i=0;i<moves.size();i++){
        int x = moves[i]-1;
        int index = 0;
        
        while(index < board.size() && board[index][x]==0)
            index++;
        
        if(index >= board.size())
            continue;

        if(!s.empty()){
            int top = s.top();
            if(top == board[index][x]){
                answer += 2;
                board[index][x] = 0;
                s.pop();
            }
            else{
                s.push(board[index][x]);
                board[index][x] = 0;
            }   
        }
        else{
            s.push(board[index][x]);
            board[index][x] = 0;
        }    
    }
    return answer;
}
