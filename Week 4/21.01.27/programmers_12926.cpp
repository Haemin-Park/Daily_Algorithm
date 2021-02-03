#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for(int i=0;i<s.length();i++){
        if(isalpha(s[i])){
            if(isupper(s[i])){
                if(s[i]+n<='Z')
                    s[i]+=n;
                else
                    s[i]=s[i]+n-26;
            }
            else{
                if(s[i]+n<='z')
                    s[i]+=n;
                else
                    s[i]=s[i]+n-26;
            }

        }
    }
    return s;
}
