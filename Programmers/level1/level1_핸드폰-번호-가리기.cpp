#include <string>
#include <vector>

//프로그래머스 level1_핸드폰-번호-가리기

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int size = phone_number.length();
    for(int i=0;i<size;i++){
        answer += i<size-4?'*':phone_number[i];
    }
    return answer;
}