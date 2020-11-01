class Solution {

  public String restoreString(String s, int[] indices) {
    int len = s.length();
    char[] c = new char[len];

    for (int i = 0; i < len; i++) {
      c[indices[i]] = s.charAt(i);
    }
    return new String(c);
  }
}
