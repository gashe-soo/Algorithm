class Solution {

  public int majorityElement(int[] nums) {
    Map<Integer, Integer> m = new HashMap<>();
    for (int i : nums) {
      m.put(i, m.getOrDefault(i, 0) + 1);
    }

    for (int i : nums) {
      if (m.get(i) > nums.length / 2) return i;
    }
    return 0;
  }
}
