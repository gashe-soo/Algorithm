class Solution {
public:
    string ignoreSign(string email)
    {
        string local, domain;

        for (int i = 0; i < email.size(); i++) {
            if (email[i] == '@') {
                local = email.substr(0, i);
                domain = email.substr(i);
                break;
            }
        }

        string realLocal;
        for (char c : local) {
            if (c == '.') {
                continue;
            } else if (c == '+') {
                break;
            }
            realLocal += c;
        }

        return realLocal + domain;
    }

    int numUniqueEmails(vector<string>& emails)
    {
        unordered_map<string, int> m;

        for (string email : emails) {
            string ret = ignoreSign(email);
            m[ret]++;
        }

        return m.size();
    }
};