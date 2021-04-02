import java.util.HashMap;

class Solution {
    public int[] solution(String[] gems) {
        int[] answer = new int[2];
        HashMap<String, Boolean> totalCount = new HashMap<>();
        HashMap<String, Integer> count = new HashMap<>();
        
        for(String gem: gems){
            totalCount.put(gem,true);
        }
        
        int totalCnt = totalCount.size();
        
        int l = 0;
        int minRange = 100001;
        
        for(int r = 0;r<gems.length;r++){
            count.put(gems[r], count.getOrDefault(gems[r],0)+1);
            
            if(totalCnt == count.size()){
                while(count.get(gems[l])>1){
                    count.put(gems[l], count.get(gems[l])-1);
                    l++;
                }
                
                if(minRange> r-l){
                    minRange = r-l;
                    answer[0] = l+1;
                    answer[1] = r+1;
                }
                count.remove(gems[l]);
                l++;
            }          
            
        }
     
        return answer;
    }
}