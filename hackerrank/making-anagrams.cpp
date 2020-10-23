#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b)
{
    int answer = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    unordered_map<char, int> A, B;

    for (int i = 0; i < a.size(); i++) {
        A[a[i]]++;
    }

    for (int i = 0; i < b.size(); i++) {
        B[b[i]]++;
    }

    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;

        if (A.find(c) == A.end() && B.find(c) == B.end())
            continue;
        if (A.find(c) != A.end() && B.find(c) == B.end()) {
            answer += A[c];
        } else if (A.find(c) == A.end() && B.find(c) != B.end()) {
            answer += B[c];
        } else {
            answer += abs(A[c] - B[c]);
        }
    }
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
