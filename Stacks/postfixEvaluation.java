import java.util.*;

class postfixEvaluation {
  public static int evaluatePostfix(String[] arr) {
    Stack<Integer> st = new Stack<>();

    for (String s : arr) {
      if (Character.isDigit(s.charAt(0)) || (s.length() > 1 && s.charAt(0) == '-')) {
        st.push(Integer.parseInt(s));
      } else {
        int b = st.pop();
        int a = st.pop();

        switch (s.charAt(0)) {
          case '+':
            st.push(a + b);
            break;

          case '-':
            st.push(a - b);
            break;

          case '*':
            st.push(a * b);
            break;

          case '/':
            st.push((int) Math.floor((double) a / b));
            break;

          case '^':
            st.push((int) Math.pow(a, b));
            break;
        }
      }
    }

    return st.pop();
  }

  public static void main(String[] args) {
    String arr[] = {"2", "3", "1", "*", "+", "9", "-"};
    System.out.println(evaluatePostfix(arr));
  }
}
