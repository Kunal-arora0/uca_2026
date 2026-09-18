class ListNode {
  int val;
  ListNode next;

  public ListNode() {}

  public ListNode(int val) {
    this.val = val;
    this.next = null;
  }
}

class searchLinkedList {
  public static boolean isContains(ListNode list1, ListNode list2) {
    if (list1 == null)
      return true;
    if (list2 == null)
      return false;

    ListNode temp2 = list2;

    while (temp2 != null) {
      ListNode t1 = list1;
      ListNode t2 = temp2;

      while (t1 != null && t2 != null && t1.val == t2.val) {
        t1 = t1.next;
        t2 = t2.next;
      }

      if (t1 == null) {
        return true;
      }

      temp2 = temp2.next;
    }

    return false;
  }

  public static void main(String[] args) {
    ListNode tc1_list1 = new ListNode(1);
    tc1_list1.next = new ListNode(2);
    tc1_list1.next.next = new ListNode(3);
    tc1_list1.next.next.next = new ListNode(4);

    ListNode tc1_list2 = new ListNode(1);
    tc1_list2.next = new ListNode(2);
    tc1_list2.next.next = new ListNode(2);
    tc1_list2.next.next.next = new ListNode(1);
    tc1_list2.next.next.next.next = new ListNode(2);
    tc1_list2.next.next.next.next.next = new ListNode(3);

    System.out.println(isContains(tc1_list1, tc1_list2));

    ListNode tc2_list1 = new ListNode(3);
    tc2_list1.next = new ListNode(4);
    tc2_list1.next.next = new ListNode(5);

    ListNode tc2_list2 = new ListNode(3);
    tc2_list2.next = new ListNode(7);
    tc2_list2.next.next = new ListNode(3);
    tc2_list2.next.next.next = new ListNode(4);
    tc2_list2.next.next.next.next = new ListNode(5);

    System.out.println(isContains(tc2_list1, tc2_list2));
  }
}
