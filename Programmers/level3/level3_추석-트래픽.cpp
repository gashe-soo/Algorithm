#include <string>
#include <vector>
#include <algorithm>

//프로그래머스 level3_추석-트래픽

using namespace std;

// 1. 시간을 모두 정수로 변환.
// 2. 시간별 1초후에 포함되어있는 지 확인
// 2-1. 확인할 경우는 시작, 완료 시간만 확인하면 된다.
// 3. 시작 시간, 완료 시간 순으로 정렬해서 각각 확인.

bool cmp(pair<int,int> a, pair<int,int> b){return a.first<b.first;}
bool cmp2(pair<int,int> a, pair<int,int> b){return a.second<b.second;}

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<int,int>> v;
    
    if(lines.size()==1)
        return 1;
    
    for(int i = 0;i<lines.size();i++){
        // 정수로 변환
        string log = lines[i];
        int t, sec;
        t = stoi(log.substr(11,2))*3600*1000 + stoi(log.substr(14,2))*60*1000 + stod(log.substr(17,6))*1000;
    
        sec = stod(log.substr(24,log.length()-25))*1000-1;
        v.push_back({t-sec,t});
    }
    // 시작 시간순으로 정렬
    sort(v.begin(),v.end(),cmp);
    
    // 시작 시간부터 확인
    for(int i = 0;i<v.size();i++){
        int cnt =1;
        for(int j = i+1;j<v.size();j++){
            if(v[j].first <= v[i].first+999 || v[j].second <=v[i].first+999) // 1초 이내에 포함
                cnt++;
        }
        answer = max(answer,cnt);
    }
    
    // 완료 시간 순으로 정렬
    sort(v.begin(),v.end(),cmp2);
    for(int i = 0;i<v.size();i++){
        int cnt =1;
        for(int j = i+1;j<v.size();j++){
            if(v[j].first <= v[i].second+999 || v[j].second <=v[i].second+999)
                cnt++;
        }
        answer = max(answer,cnt);
    }
    
    return answer;
}