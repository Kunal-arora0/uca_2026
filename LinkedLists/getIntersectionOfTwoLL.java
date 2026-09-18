import java.util.*;

class ListNode {
  int val;
  ListNode next;

  public ListNode() {}

  public ListNode(int val) {
    this.val = val;
    this.next = null;
  }
}

public class getIntersectionOfTwoLL {
  public static ListNode getIntersection(ListNode head1, ListNode head2) {
    ListNode dummy = new ListNode(-1);
    ListNode curr = dummy;

    while (head1 != null && head2 != null) {
      if (head1.val == head2.val) {
        curr.next = new ListNode(head1.val);
        curr = curr.next;
        head1 = head1.next;
        head2 = head2.next;
      } else if (head1.val < head2.val) {
        head1 = head1.next;
      } else {
        head2 = head2.next;
      }
    }

    return dummy.next;
  }

  public static void printLL(ListNode head) {
    if (head == null)
      return;

    ListNode temp = head;

    while (temp != null) {
      System.out.print(temp.val);
      if (temp.next != null) {
        System.out.print("->");
      }
      temp = temp.next;
    }
  }

  public static void main(String[] args) {
    // ==========================================
    // Test Case 1
    // head1 = 1 -> 2 -> 2 -> 3 -> 4
    // head2 = 2 -> 2 -> 2 -> 4
    // ==========================================
    ListNode head1 = new ListNode(1);
    head1.next = new ListNode(2);
    head1.next.next = new ListNode(2);
    head1.next.next.next = new ListNode(3);
    head1.next.next.next.next = new ListNode(4);

    ListNode head2 = new ListNode(2);
    head2.next = new ListNode(2);
    head2.next.next = new ListNode(2);
    head2.next.next.next = new ListNode(4);

    // ==========================================
    // Test Case 2
    // head3 = 1 -> 2 -> 3 -> 4 -> 6
    // head4 = 2 -> 4 -> 6 -> 8
    // ==========================================
    ListNode head3 = new ListNode(1);
    head3.next = new ListNode(2);
    head3.next.next = new ListNode(3);
    head3.next.next.next = new ListNode(4);
    head3.next.next.next.next = new ListNode(6);

    ListNode head4 = new ListNode(2);
    head4.next = new ListNode(4);
    head4.next.next = new ListNode(6);
    head4.next.next.next = new ListNode(8);

    ListNode result1 = getIntersection(head1, head2);
    printLL(result1);

    System.out.println();
    System.out.println("Testcase 2");

    ListNode result2 = getIntersection(head3, head4);
    printLL(result2);
  }
}
