#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// 프로그래머스 level2 폰켓몬

int solution(vector<int> nums)
{
    int size = nums.size()/2;
    //중복제거
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    
    // n/2와 중복제거한 배열 길이 중 짧은 것을 리턴
    return min(size,(int)nums.size());
    
    // set을 이용한 풀이
//     set<int> s(nums.begin(),nums.end());
//     return min(nums.size()/2, s.size());
}