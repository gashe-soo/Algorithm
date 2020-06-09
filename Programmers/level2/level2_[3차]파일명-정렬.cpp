#include <string>
#include <vector>
#include <utility>
#include <algorithm>

// 프로그래머스 level2_[3차]파일명-정렬

using namespace std;

// 1. file별 Head, number을 구분한다.
// 2. 배열에 head, number, 들어온 순서대로 저장.
// 3. 정렬.

vector<pair<vector<string>,int>> file;

// 1+2.
void split(string f, int i){
    int len = f.length();
    string head, num;
    int start,end;
    
    // 1. Head 구분. 숫자 전까지.
    for(int i =0;i<len;i++){
        if(f[i]>='0' && f[i]<='9'){
            start = i;
            break;
        }
    }     
    
    // 1. num 구분
    for(int i = start;i<len;i++){
        if(f[i]<'0' || f[i]>'9'){
            end = i;
            break;
        }
    }
    head = f.substr(0,start);
    std::transform(head.begin(),head.end(),head.begin(),::toupper);
    num = f.substr(start, end-start);    
    
    // 2.
    file.push_back({{head,num},i});
    return;    
}

// 3. 정렬
bool cmp(pair<vector<string>,int> a, pair<vector<string>,int> b){
    if(a.first[0] == b.first[0]){
        if(stoi(a.first[1]) ==  stoi(b.first[1]))
            return a.second < b.second;
        return stoi(a.first[1]) <  stoi(b.first[1]);
    }
    return a.first[0]<b.first[0];
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    for(int i=0;i<files.size();i++){
        split(files[i],i);
    }
    
    sort(file.begin(),file.end(),cmp);
    
    for(auto p: file){
        answer.push_back(files[p.second]);
    }
    
    return answer;
}