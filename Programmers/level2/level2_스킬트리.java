class Solution {

  public int convert(char c) {
    return c - 'A';
  }

  public boolean check(String skill, String tree) {
    int[] chk = new int[26];

    for (int i = 0; i < skill.length(); i++) {
      int idx = convert(skill.charAt(i));
      chk[idx] = i + 1;
    }
    int now = 1;
    for (int i = 0; i < tree.length(); i++) {
      int idx = convert(tree.charAt(i));
      if (chk[idx] == 0) continue;

      if (chk[idx] == now) {
        now++;
      } else return false;
    }
    return true;
  }

  public int solution(String skill, String[] skill_trees) {
    int answer = 0;

    for (String tree : skill_trees) {
      if (check(skill, tree)) answer++;
    }

    return answer;
  }
}
