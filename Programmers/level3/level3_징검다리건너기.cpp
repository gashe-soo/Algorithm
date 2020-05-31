#include <string>
#include <vector>

//프로그래머스 level3 징검다리 건너기

using namespace std;

bool count(int mid, vector<int> stones, int k){
    int cnt =0;
    for(int i=0;i<stones.size();i++){
        if(stones[i]<=mid){
            cnt++;
        }else{
            cnt =0;
        }
        if(cnt>=k)
            return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left = 0, right = 200000000;
    
    while(left<=right){
        int mid = (left+right)/2;
        
        if(count(mid,stones,k)){
            left= mid+1;
        }else
            right = mid-1;
    }
    answer = left;
    return answer;
}