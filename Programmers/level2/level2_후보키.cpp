#include <string>
#include <vector>
#include <set>

// 프로그래머스 level2_후보키

using namespace std;

// 1. 브루트포스로 모든 조합 확인
// 2. 조합별 문자열의 합이 유일성을 만족하는지 확인
// 3. 기존의 후보 키와 비교하여 최소성을 만족하는 지 확인

vector<string> ret;
vector<vector<string>> re;
int n, size;

// 2. 유일성 확인
bool isKey(string num){
    set<string> s;
    string temp;
    for(int i=0;i<re.size();i++){
        temp.clear();
        for(char c : num){
            int idx = c-'0';
            temp += re[i][idx]+";";
        }
        s.insert(temp);
    }
    return s.size()==re.size();
}

// 3. 최소성 확인
bool contain(string a, string b){
    int cnt = 0;
    int a_idx = 0;
    for(int i=0;i<b.length();i++){
        if(a[a_idx]==b[i]){
            a_idx++;
            cnt++;
        }
    }

    return cnt == a.length();
}

//1. 
void go(int end, string val){
    if(end == val.length()){
        if(isKey(val)){ //2.
            for(string num : ret){
                if(contain(num,val))    //3.
                    return;
            }
            ret.push_back(val);
        }
        return;
    }
    int t = val.length()? val[val.length()-1] -'0': -1;

    for(int i=t+1;i<n;i++){
        go(end, val+to_string(i));
    }
}


int solution(vector<vector<string>> relation) {
    int answer = 0;
    re = relation;
    n = relation[0].size();
    size = relation.size();

    for(int i=1;i<=n;i++){
        go(i,"");
    }
    
    return ret.size();
}