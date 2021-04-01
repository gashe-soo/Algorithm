import java.util.*;

class Solution {

  public long solution(int n, int[] works) {
    long answer = 0;
    PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

    for (int work : works) {
      pq.add(work);
    }

    while (n > 0) {
      n--;
      int num = pq.poll();
      if (num == 0) {
        break;
      }
      num--;
      pq.add(num);
    }

    while (!pq.isEmpty()) {
      int num = pq.poll();
      answer += (num * num);
    }

    return answer;
  }
}
