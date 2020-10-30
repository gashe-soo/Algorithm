class Solution {

  public int numIdenticalPairs(int[] nums) {
    int ans = 0;
    Map<Integer, Integer> m = new HashMap<>();
    for (int num : nums) {
      if (m.containsKey(num)) {
        int v = m.get(num);
        m.put(num, ++v);
      } else {
        m.put(num, 1);
      }
    }

    for (int num : m.keySet()) {
      int v = m.get(num);
      ans += v * (v - 1) / 2;
    }
    return ans;
  }
}
