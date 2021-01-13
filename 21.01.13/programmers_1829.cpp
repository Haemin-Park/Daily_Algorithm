#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    bool visit[100][100]={false};
    queue<pair<int,int>> q;
    int area_n=0;
    int max_area=0;
    
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!visit[i][j] && picture[i][j]!=0){
                q.push(make_pair(j,i));
                visit[i][j]=true;
                //bfs
                int cnt=0;
                cnt++;
                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    for(int i=0;i<4;i++){
                        int nx=x+dx[i];
                        int ny=y+dy[i];

                        if(nx<0||ny<0||nx>=n||ny>=m)
                            continue;

                        if(!visit[ny][nx]&&picture[ny][nx]==picture[y][x]){
                            q.push(make_pair(nx,ny));
                            visit[ny][nx]=true;
                            cnt++;
                        }
                    }
                }
                max_area=max(max_area,cnt);
                
                area_n++;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = area_n;
    answer[1] = max_area;
    return answer;
}
