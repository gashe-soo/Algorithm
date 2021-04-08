import java.util.*;

class Solution {

  public int findFirstNumIdx(String file) {
    for (int i = 0; i < file.length(); i++) {
      if (file.charAt(i) >= '0' && file.charAt(i) <= '9')
        return i;
    }
    return file.length();
  }

  public int findFirstTailIdx(String file, int idx) {
    for (int i = idx; i < file.length(); i++) {
      if (file.charAt(i) < '0' || file.charAt(i) > '9')
        return i;
    }
    return file.length();
  }

  public File cal(String file, int idx) {
    String head = "";
    String num = "";
    String tail = "";

    int firstNumIdx = findFirstNumIdx(file);
    int firstTailIdx = findFirstTailIdx(file, firstNumIdx);

    head = file.substring(0, firstNumIdx).toLowerCase();
    num = file.substring(firstNumIdx, firstTailIdx);

    if (firstTailIdx != file.length())
      tail = file.substring(firstTailIdx);

    return new File(head, num, tail, idx);
  }

  public String[] solution(String[] files) {
    int n = files.length;
    String[] answer = new String[n];
    ArrayList<File> arr = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      arr.add(cal(files[i], i));
    }

    Collections.sort(arr, (a, b) -> {
      if ((a.head.equals(b.head)) && (Integer.parseInt(a.num) == Integer.parseInt(b.num)))
        return a.idx - b.idx;
      else if (a.head.equals(b.head))
        return (Integer.parseInt(a.num) - Integer.parseInt(b.num));
      return a.head.compareTo(b.head);
    });

    for (int i = 0; i < n; i++) {
      int idx = arr.get(i).idx;
      answer[i] = files[idx];
    }

    return answer;
  }

  class File {

    String head;
    String num;
    String tail;
    int idx;

    public File(String head, String num, String tail, int idx) {
      this.head = head;
      this.num = num;
      this.tail = tail;
      this.idx = idx;
    }
  }
}
