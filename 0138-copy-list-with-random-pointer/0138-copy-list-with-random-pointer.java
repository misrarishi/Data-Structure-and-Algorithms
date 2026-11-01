/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if (head == null)
            return null;
        HashMap<Node, Node> map = new HashMap<>();
        Node newHead = new Node(head.val);
        Node oldTemp = head.next;
        Node newTemp = newHead;
        map.put(head, newHead);
        while (oldTemp != null) {
            Node copy = new Node(oldTemp.val);
            map.put(oldTemp, copy);
            newTemp.next = copy;
            oldTemp = oldTemp.next;
            newTemp = newTemp.next;
        }
        oldTemp = head;
        newTemp = newHead;
        while (oldTemp != null) {
            newTemp.random = (oldTemp.random != null) ? map.get(oldTemp.random) : null;
            oldTemp = oldTemp.next;
            newTemp = newTemp.next;
        }
        return newHead;

    }
}