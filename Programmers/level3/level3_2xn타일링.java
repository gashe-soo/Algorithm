class Solution {
    static final int MOD = 1_000_000_007;
    
    public int solution(int n) {
        int answer = 0;
        
        int first = 1;
        int second = 2;
        
        for(int i=2;i<n;i++){
            answer = (first + second)%MOD;
            first = second;
            second = answer;
        }
        
        return second;
    }
}