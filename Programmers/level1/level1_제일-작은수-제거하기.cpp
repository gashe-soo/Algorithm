#include <string>
#include <vector>
#include <algorithm>

//프로그래머스 level1_제일-작은수-제거하기

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min = *min_element(arr.begin(),arr.end());
    
    for(int x : arr){
        if(x != min)
            answer.push_back(x);
    }
    
    if(answer.size()==0)
        return {-1};
    return answer;
}