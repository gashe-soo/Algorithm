#include <string>
#include <vector>
#include <algorithm>

//프로그래머스 level2_최댓값과-최솟값

using namespace std;

string solution(string s) {
    vector<int> ret;
    string t;
    for(int i = 0;i<s.length();i++){
        if(s[i] !=' ')
            t += s[i];
        else{
            ret.push_back(stoi(t));
            t.clear();
        }
    }
    ret.push_back(stoi(t));
    
    int max = *max_element(ret.begin(),ret.end());
    int min = *min_element(ret.begin(),ret.end());
    return to_string(min)+ " "+to_string(max);
    
}