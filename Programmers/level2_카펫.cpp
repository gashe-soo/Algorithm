#include <string>
#include <vector>

using namespace std;
// 프로그래머스 level2 카펫

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int h=3;
    int w = brown/2+2-h;
    
    // w은 줄고 h은 늘리면서 w*h이 전체 칸 수와 맞는 지 확인.
    while(w>=h){
        if(w*h == (brown+yellow)) break;
        w--;
        h++;
    }
    
    answer.push_back(w);
    answer.push_back(h);
    
    return answer;
}