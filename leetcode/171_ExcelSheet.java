class Solution {

  public int titleToNumber(String s) {
    int ret = 0;
    int time = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
      int val = s.charAt(i) - 'A' + 1;
      ret += time * val;
      time *= 26;
    }
    return ret;
  }
}
