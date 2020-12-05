class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        int n = beginWord.size();

        unordered_map<string, vector<string>> m;
        unordered_map<string, bool> v;

        for (string word : wordList) {

            for (int i = 0; i < n; i++) {
                string nw = word.substr(0, i) + "*" + word.substr(i + 1, n);
                m[nw].push_back(word);
            }
        }

        queue<pair<string, int>> q;
        q.push({ beginWord, 1 });
        v[beginWord] = 1;

        while (!q.empty()) {
            string now = q.front().first;
            int cnt = q.front().second;
            q.pop();

            for (int i = 0; i < n; i++) {
                string word = now.substr(0, i) + "*" + now.substr(i + 1, n);
                for (string to : m[word]) {
                    if (to == endWord)
                        return cnt + 1;
                    if (v[to])
                        continue;
                    q.push({ to, cnt + 1 });
                    v[to] = 1;
                }
            }
        }

        return 0;
    }
};