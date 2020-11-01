class Solution {

  public int numberOfSteps(int num) {
    int ans = 0;
    while (num != 0) {
      ans++;
      if (num % 2 == 1) {
        num -= 1;
      } else {
        num /= 2;
      }
    }
    return ans;
  }
}
