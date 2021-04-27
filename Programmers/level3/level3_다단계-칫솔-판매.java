import java.util.*;

class Solution {

    static HashMap<String, Node> nodeList = new HashMap<>();
    static HashMap<String, Integer> result = new HashMap<>();

    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        int size = enroll.length;
        int[] answer = new int[size];

        nodeList.put("-", new Node("-"));
        for (int i = 0; i < size; i++) {
            String name = enroll[i];
            nodeList.put(name, new Node(name));
        }

        for (int i = 0; i < size; i++) {
            Node parent = nodeList.get(referral[i]);
            Node c = nodeList.get(enroll[i]);

            c.parent = parent;
        }

        for (int i = 0; i < amount.length; i++) {
            String name = seller[i];
            int val = amount[i] * 100;
            paid(name, val);
        }

        for (int i = 0; i < size; i++) {
            String name = enroll[i];
            answer[i] = result.containsKey(name) ? result.get(name) : 0;
        }

        return answer;
    }

    public void paid(String name, int amount) {
        if (name.equals("-"))
            return;

        Node cur = nodeList.get(name);
        int commission = amount / 10;
        int mine = amount - commission;

        result.put(name, result.getOrDefault(name, 0) + mine);

        paid(cur.parent.name, commission);

    }

    static class Node {
        int amount;
        String name;

        Node parent;

        Node(String name) {
            this.name = name;
        }

    }
}