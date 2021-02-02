#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    bool isSkillTree=true;
    int pre=-1;
    int preIdx=-1;
    for(int i=0;i<skill_trees.size();i++){
        for(int j=0;j<skill.length();j++){
            auto iter=find(skill_trees[i].begin(),skill_trees[i].end(),skill[j]);
            if(iter!=skill_trees[i].end()){
                int curIdx=iter-skill_trees[i].begin();
                if(pre==j-1 && preIdx<curIdx){
                    pre=j;
                    preIdx=curIdx;
                }
                else{
                    isSkillTree=false;
                    break;
                }
            }
        }
        if(isSkillTree)
            answer++;
        isSkillTree=true;
        pre=-1;
        preIdx=-1;
    }

    return answer;
}
