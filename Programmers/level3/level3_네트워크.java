class Solution {

  public int solution(int n, int[][] computers) {
    int answer = 0;

    boolean[] v = new boolean[n];

    for (int i = 0; i < n; i++) {
      if (!v[i]) {
        answer++;
        dfs(i, v, computers);
      }
    }

    return answer;
  }

  public void dfs(int now, boolean[] v, int[][] computers) {
    int n = v.length;
    v[now] = true;
    for (int i = 0; i < n; i++) {
      if (computers[now][i] == 1 && !v[i]) {
        dfs(i, v, computers);
      }
    }
  }
}
