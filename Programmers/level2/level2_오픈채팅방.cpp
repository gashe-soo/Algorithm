#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
unordered_map<string, string> user;

vector<string> split(string str)
{
    vector<string> ret;
    string temp;
    for (char c : str) {
        if (c == ' ') {
            ret.push_back(temp);
            temp.clear();
        } else {
            temp += c;
        }
    }
    ret.push_back(temp);
    return ret;
}

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    vector<vector<string>> records;

    for (string s : record) {
        vector<string> ret = split(s);
        records.push_back(ret);
        if (ret[0] == "Enter" || ret[0] == "Change")
            user[ret[1]] = ret[2];
    }

    for (string s : record) {
        vector<string> r = split(s);
        string userId = user[r[1]];
        string postFix;
        if (r[0] == "Enter")
            postFix = "님이 들어왔습니다.";
        else if (r[0] == "Leave")
            postFix = "님이 나갔습니다.";
        else
            continue;
        answer.push_back(userId + postFix);
    }

    return answer;
}