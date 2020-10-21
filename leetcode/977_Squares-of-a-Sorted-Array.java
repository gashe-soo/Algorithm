class Solution {

  public int[] sortedSquares(int[] A) {
    int lo = 0;
    int hi = A.length - 1;
    int[] ret = new int[A.length];
    int i = A.length - 1;

    while (lo <= hi) {
      int h = Math.abs(A[hi]);
      int l = Math.abs(A[lo]);
      if (h >= l) {
        ret[i] = h * h;
        hi--;
      } else {
        ret[i] = l * l;
        lo++;
      }
      i--;
    }
    return ret;
  }
}
