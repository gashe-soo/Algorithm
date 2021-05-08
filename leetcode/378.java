class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for(int[] row : matrix){
            for(int col : row){
                pq.add(col);
            }
        }
        
        while(k>1){
            pq.poll();
            k--;
        }
        return pq.poll();
        
    }
}