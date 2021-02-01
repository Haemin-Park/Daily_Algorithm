#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(pair<int,double> a, pair<int,double> b){
    if(a.second!=b.second)
        return a.second>b.second;
    else{
        return a.first<b.first;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int,double> m;
    double a=0,b=0; //a: 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수, b: 스테이지에 도달한 플레이어의 수
    vector<pair<int,double>> v;

    sort(stages.begin(),stages.end());
    double s; // 스테이지
    for(int i=0;i<stages.size();i++){
        s=stages[i];
        if(m.find(s)==m.end() && s<=N){
            for(int j=i;j<stages.size();j++){
                if(s==stages[j])
                    a++;
                b++;
            }
            m[s]=a/b;   
            a=0,b=0;
        }
    }

    for(int i=1;i<=N;i++){
        v.push_back(make_pair(i,m[i]));
    }
    sort(v.begin(),v.end(),cmp);

    for(int i=0;i<v.size();i++){
        answer.push_back(v[i].first);
    }

    return answer;
}
