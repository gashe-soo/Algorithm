class Solution {

  public int numJewelsInStones(String J, String S) {
    //         Map<String,Integer> map = new HashMap<>();
    //         int ans = 0;
    //         for(int i=0;i<S.length();i++){
    //             char c = S.charAt(i);
    //             String now = Character.toString(c);
    //             map.put(now, map.getOrDefault(now,0)+1);
    //         }

    //         for(int i=0;i<J.length();i++){
    //             char c = J.charAt(i);
    //             String now = Character.toString(c);
    //             if(map.containsKey(now)){
    //                 ans += map.get(now);
    //             }
    //         }
    //         return ans;
    int count = 0;

    for (int i = 0; i < J.length(); i++) {
      char c = J.charAt(i);
      for (int k = 0; k < S.length(); k++) {
        char ch = S.charAt(k);
        if (c == ch) {
          count++;
        }
      }
    }
    return count;
    //         List<Character> list = new ArrayList();
    //         int sum = 0;
    //         int i = 0, j = 0;

    //         while(i < J.length()){
    //             list.add(J.charAt(i));
    //             i++;
    //         }

    //         while(j < S.length()){
    //             if(list.contains(S.charAt(j)))
    //                 sum++;
    //             j++;
    //         }

    //         return sum;

  }
}
