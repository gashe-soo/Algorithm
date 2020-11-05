class Solution {

  public List<String> fizzBuzz(int n) {
    final String three = "Fizz";
    final String five = "Buzz";
    final String both = "FizzBuzz";

    List<String> ans = new ArrayList<>();

    for (int i = 1; i <= n; i++) {
      if (i % 15 == 0) {
        ans.add(both);
      } else if (i % 3 == 0) {
        ans.add(three);
      } else if (i % 5 == 0) {
        ans.add(five);
      } else {
        ans.add(Integer.toString(i));
      }
    }
    return ans;
  }
}
