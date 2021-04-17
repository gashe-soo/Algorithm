import java.util.*;

class Solution {
    public int[][] solution(int[][] nodeinfo) {
        int n = nodeinfo.length;
        int[][] answer = new int[2][n];

        List<Node> nodeList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int x = nodeinfo[i][0];
            int y = nodeinfo[i][1];

            nodeList.add(new Node(x, y, i + 1));
        }
        Collections.sort(nodeList, (a, b) -> {
            if (a.y == b.y)
                return a.x - b.x;
            return b.y - a.y;
        });

        Tree tree = new Tree();
        for (Node node : nodeList) {
            tree.makeTree(node);
        }

        tree.preOrder(tree.root);
        tree.postOrder(tree.root);

        for (int i = 0; i < tree.preList.size(); i++) {
            answer[0][i] = tree.preList.get(i);
            answer[1][i] = tree.postList.get(i);
        }

        return answer;
    }

    class Tree {
        public Node root;
        public List<Integer> preList = new ArrayList<>();
        public List<Integer> postList = new ArrayList<>();

        public void makeTree(Node node) {
            if (root == null) {
                root = node;
                return;
            }
            find(node, root);
        }

        public void find(Node node, Node root) {
            if (node.x < root.x) {
                if (root.left == null) {
                    root.left = node;
                    return;
                }
                find(node, root.left);
                return;
            }
            if (root.right == null) {
                root.right = node;
                return;
            }
            find(node, root.right);
        }

        public void preOrder(Node node) {
            if (node == null)
                return;

            preList.add(node.idx);
            preOrder(node.left);
            preOrder(node.right);
        }

        public void postOrder(Node node) {
            if (node == null)
                return;

            postOrder(node.left);
            postOrder(node.right);
            postList.add(node.idx);
        }

    }

    class Node {
        int x;
        int y;
        int idx;
        Node left;
        Node right;

        public Node(int x, int y, int idx) {
            this.x = x;
            this.y = y;
            this.idx = idx;
            this.left = this.right = null;
        }
    }
}