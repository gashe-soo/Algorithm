#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s)
{
    int len = s.size();

    unordered_map<string, int> m;
    for (int i = 1; i < len; i++) {
        for (int j = 0; j <= len - i; j++) {
            string sub = s.substr(j, i);
            sort(sub.begin(), sub.end());
            m[sub]++;
        }
    }
    int answer = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        int val = it->second;

        if (val >= 2)
            answer += (val - 1) * val / 2;
    }
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
