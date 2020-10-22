class Solution {

  /*
    투 포인터
    */

  public int lengthOfLongestSubstring(String s) {
    Map<Character, Integer> map = new HashMap<>();
    int res = 0, left = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (map.containsKey(s.charAt(i))) {
        res = Math.max(i - left, res);
        left = Math.max(map.get(s.charAt(i)) + 1, left);
      }
      map.put(s.charAt(i), i);
    }
    return Math.max(res, s.length() - left);
  }
}
