import java.util.LinkedList; //import
import java.util.Queue; //import
import java.util.ArrayList;

class Solution {
    public int solution(int n, int[][] edge) {
        int answer = 0;
        int[] dist = new int[n+1];
        ArrayList<Integer>[] adj = new ArrayList[n+1];
        
        for(int i=0;i<=n;i++){
            adj[i] = new ArrayList<>();
        }
        
        for(int i=0;i<edge.length;i++){
            int a = edge[i][0];
            int b = edge[i][1];
            
            adj[a].add(b);
            adj[b].add(a);
        }
        
        Queue<Integer> queue = new LinkedList<>();
        
        queue.add(1);
        dist[1] = 1;
        
        while(!queue.isEmpty()){
            int from = queue.poll();
            
            for(int to : adj[from]){
                if(dist[to]!=0)
                    continue;
                dist[to] = dist[from]+1;
                queue.add(to);
            }
        }
        int maxVal = 0;
        for(int i=1;i<=n;i++){
            if(maxVal<dist[i]){
                maxVal = dist[i];
                answer = 1;
            }else if(maxVal == dist[i]){
                answer++;
            }
        }
        
        return answer;
    }
}