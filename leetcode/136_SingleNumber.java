class Solution {

  public int singleNumber(int[] nums) {
    // Map<Integer,Integer> m = new HashMap<>();
    // for(int i :nums){
    //     m.put(i,m.getOrDefault(i,0)+1);
    // }
    // for(int i:nums){
    //     if(m.get(i)==1)
    //         return i;
    // }
    // return 0;

    // using bitwise

    int a = 0;

    for (int i : nums) {
      a ^= i;
    }
    return a;
  }
}
