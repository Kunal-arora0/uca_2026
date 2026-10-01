import java.util.*;

public class BST{
    Node root;
    
    BST(){
        this.root = null;
    }

    public int getMinValue(){
        if(root == null) return -1;
        

        return getMinValue(root);    
    }
    
    private int getMinValue(Node root){
        if(root.left == null){
            return root.val;
        }

        return getMinValue(root.left);
    }

    public Node getMinNode(){
        if(root == null) return null;

        return getMinNode(root);
    }

    private Node getMinNode(Node root){
        if(root.left == null){
            return root;
        }
        return getMinNode(root.left);

    }

    
    public int getMaxValue(){
        if(root == null) return -1;
        return getMaxValue(root.right);
    }

    private int getMaxValue(Node root){
      if(root.right == null){
            return root.val;
        }

        return getMaxValue(root.right);
    }

    public Node getMaxNode(){
        if(root == null) return null;
       
        return getMaxNode(root.right);
    }

    private Node getMaxNode(Node root){
         if(root.right == null){
            return root;
        }

        return getMaxNode(root.right);
    }

    public void deleteMin(){
        
        if(root == null) return;

        root = delMin(root);

    }

    public Node delMin(Node root){
        

        if(root.left == null){
            return root.right;
        }


      root.left =  delMin(root.left);
      return root;
    }
    
}
