import java.util.*;

class ListNode{
	int val;
	ListNode next;

	public ListNode(int val){
		this.val = val;
		this.next = null;
	}
}



public class reverseLinkedList{

	public static ListNode reverseLL(ListNode current, ListNode prev){
		
		if(current == null){
			return prev;
		}


		ListNode next = current.next;
		current.next = prev;

		return reverseLL(next , current);
	}

	public static void printLL(ListNode head){

		if(head == null) return;

		ListNode temp = head;

		while(temp!=null){
			System.out.print(temp.val);
			if(temp.next!=null){
				System.out.print("->");
			}
			temp = temp.next;
		}
	}


	public static void main(String[] args){
		
		ListNode root = new ListNode(1);
		ListNode temp = root;
		for(int i=2;i<=5;i++){
			ListNode newnode = new ListNode(i);
			temp.next = newnode;
			temp = newnode;
		}

		printLL(root);
		ListNode reversed = reverseLL(root,null);
		System.out.println();
		System.out.println("After Reversal!");
		printLL(reversed);
		
	}
}
