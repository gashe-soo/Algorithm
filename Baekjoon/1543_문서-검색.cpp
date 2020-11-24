// 백준 1543번 문서 검색

// word 찾으면 word.size만큼 이동

#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string doc, word;

    getline(cin, doc);
    getline(cin, word);
    int count = 0;

    for (int i = 0; i < doc.size(); i++) {
        int docIdx = i;
        for (int j = 0; j < word.size(); j++) {
            if (doc[docIdx] != word[j]) {
                break;
            }
            docIdx++;
            if (j == word.size() - 1) {
                i += word.size() - 1;
                count++;
            }
        }
    }
    cout << count;

    return 0;
}