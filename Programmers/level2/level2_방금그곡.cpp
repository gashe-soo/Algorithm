#include <string>
#include <vector>
#include <map>
#include <algorithm>

//프로그래머스 level2_방금그곡

using namespace std;

// 1. 제목별 시간동안 총 멜로디 음 확인
// 1-1. 곡 정보에서 시간, 제목, 음 분리
// 1-2. 음 길이 확인 => 시간동안 멜로디 음 확인
// 1-3. #을 다 소문자로 바꾸기.
// 2. m과 총 멜로디 음 비교.

// 1-1.
vector<string> split(string info){
    string temp;
    vector<string> ret;
    for(int i=0;i<info.length();i++){
        if(info[i]==','){
            ret.push_back(temp);
            temp.clear();
        }else
            temp +=info[i];
    }
    ret.push_back(temp);
    return ret;
}


// 1-2.
string countMelody(string melody, int time){
    string newMelody = changeMelody(melody);
    
    int num = newMelody.length();
    string ret;
    for(int i=0;i<time/num;i++){
        ret +=newMelody;
    }
    for(int i=0;i<time%num;i++){
        ret +=newMelody[i];
    }
    return ret;
    
}
// 1-2.
int countTime(string start, string end){
    int startTime = stoi(start.substr(0,2))*60+ stoi(start.substr(3,2));
    int endTime = stoi(end.substr(0,2))*60+ stoi(end.substr(3,2));
    
    return endTime-startTime;
}
// 1-3.
string changeMelody(string melody){
    int len = melody.length();
    string newMelody;
    for(int i=0;i < len-1;i++){
        if(melody[i] !='#'){
            if(melody[i+1] !='#')
                newMelody +=melody[i];
            else
                newMelody +=tolower(melody[i]);
        }
    }
    if(melody[len-1] !='#')
        newMelody +=melody[len-1];
    return newMelody;
}

// 조건 일치가 다수일 때, 정렬.
bool cmp(pair<string, vector<int>> a, pair<string, vector<int>> b){
    if(a.second[0] == b.second[0])
        return a.second[1] <b.second[1];
    
    return a.second[0]>b.second[0];
}

string solution(string m, vector<string> musicinfos) {
    map<string,string> music;   // 음악 제목과 멜로디
    map<string, vector<int>> playingTime;   // 제목과 재생시간, 입력 순서
    
    vector<pair<string, vector<int>>> ans;
    
    for(int i=0;i<musicinfos.size();i++){
        vector<string> song = split(musicinfos[i]);
        int time = countTime(song[0], song[1]);
        music[song[2]] = countMelody(song[3],time);
        playingTime[song[2]] = {time,i};
    }
    
    for(auto it = music.begin();it!=music.end();it++){
        string title = it->first;
        string melody = it->second;
        string obj = changeMelody(m);
        if(melody.find(obj) !=string::npos){
            ans.push_back({title, playingTime[title]});
        }
        
    }
    if(ans.size()==0)
        return "(None)";
    
    sort(ans.begin(),ans.end(),cmp);
    
    return ans[0].first;
}