import java.util.*;

class Solution {
    public int[] solution(String s) {

        HashSet<String> set = new HashSet<>();
        String[] arr = s.replaceAll("[{]", " ").replaceAll("[}]", " ").trim().split(" , ");

        Arrays.sort(arr, (a, b) -> {
            return a.length() - b.length();
        });

        int[] answer = new int[arr.length];
        int idx = 0;
        for (String str : arr) {
            for (String c : str.split(",")) {
                if (!set.contains(c)) {
                    answer[idx++] = Integer.parseInt(c);
                    set.add(c);
                }
            }

        }

        return answer;
    }

}