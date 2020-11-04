class Solution {

  public int[] smallerNumbersThanCurrent(int[] nums) {
    int[] map = new int[101];

    for (int num : nums) map[num] += 1;

    int sum = map[0];
    map[0] = 0;
    for (int i = 1; i < 101; i++) {
      int temp = map[i];
      map[i] = sum;
      sum += temp;
    }

    for (int i = 0; i < nums.length; i++) {
      nums[i] = map[nums[i]];
    }

    return nums;
  }
}
