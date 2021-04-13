import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        
        Arrays.sort(citations);
        
        int len = citations.length;
        
        for(int cite : citations){
            if(cite>=len)
                return len;
            len--;
        }
        
        return answer;
    }
}