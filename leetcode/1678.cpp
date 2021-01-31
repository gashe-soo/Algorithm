class Solution {
public:
    string interpret(string command)
    {
        string ret;

        for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'G')
                ret += 'G';
            else if (command[i] == '(') {

                if (command[i + 1] == ')')
                    ret += "o";
                else {
                    ret += "al";
                }
            }
        }
        return ret;
    }
};