#include <string>
#include <vector>
#include <algorithm>

//프로그래머스 level3_셔틀버스

using namespace std;

// 0. 시간은 정수형으로 정리.
// 1. 셔틀 출발시간 정리.
// 2. 매 출발시간마다 태울 수 있는 인원을 정리. 마지막 타임에 탈 수 있는 인원의 시작 번호 확인
// 3. 마지막 타임에서 m번째 안에 들어오는 지 확인
// 3-1. m번째 안에 들어오면 출발시간.
// 3-2. m번째 못 들어오면 m번째의 1분 빠른 시간, 출발 시간 중 더 빠른 것.
// 4. 문자열로 변환
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> time;
    vector<int> shuttle;
    
    // 0.
    for(string table : timetable){
        int t = stoi(table.substr(0,2))*60 + stoi(table.substr(3,2));
        time.push_back(t);
    }
    // timetable 오름차순 정렬
    sort(time.begin(),time.end());
    
    // 1.
    for(int i = 0;i<n;i++){
        int start = 9*60;
        shuttle.push_back(start+ t*i);
    }
    // 2.
    int idx = 0;
    int p;
    for(int i=0;i<n-1;i++){
        p = m;
        while(time[idx] <= shuttle[i] && p--){
            idx++;
        }
    }
    // 3.
    int ans;
    if(time.size()-idx>=m){ // 3-2
        ans = min(time[idx+m-1]-1, shuttle[n-1]);
    }else{ // 3-1.
        ans = shuttle[n-1];
    }
    
    // 4. 문자열로 변환
    int hour = ans/60;
    int min = ans%60;
    if(hour<10) answer +="0";
    answer +=to_string(hour)+":";
    if(min<10) answer +="0";
    answer +=to_string(min);
    
    
    return answer;
}