class Solution {
public:
    string reverseWords(string s)
    {
        //         string word;
        //         string ret;
        //         for(char c : s){
        //             if(c==' '){
        //                 reverse(word.begin(),word.end());
        //                 ret += word + c;
        //                 word.clear();
        //             }else{
        //                 word +=c;
        //             }
        //         }
        //         reverse(word.begin(),word.end());
        //         ret += word;

        //         return ret;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') { // when i is a non-space
                int j = i;
                for (; j < s.length() && s[j] != ' '; j++) { } // move j to the next space
                reverse(s.begin() + i, s.begin() + j);
                i = j - 1;
            }
        }

        return s;
    }
};