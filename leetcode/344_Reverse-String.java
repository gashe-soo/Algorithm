class Solution {
    public void reverseString(char[] s) {
        int size = s.length;
        for(int i=0;i<size/2;i++){
            char c = s[i];
            s[i] = s[size-i-1];
            s[size-i-1] = c;
        }
    }
}