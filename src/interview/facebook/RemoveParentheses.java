package interview.facebook;

import java.util.Stack;

public class RemoveParentheses {

    public String remove(String s) {
        Stack<Integer> stack = new Stack<>();
        int n = s.length();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else if (s.charAt(i) == ')') {
                if (!stack.isEmpty() && s.charAt(stack.peek()) == '(') {
                    stack.pop();
                } else {
                    stack.push(i);
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = n - 1; i >= 0; i--) {
            if (!stack.isEmpty() && stack.peek() == i) {
                stack.pop();
                continue;
            }
            sb.append(s.charAt(i));
        }
        return sb.reverse().toString();
//        int n = s.length();
//        boolean[] toBeRemoved = new boolean[n];
//        int count = 0;
//        for (int i = 0; i < n; i++) {
//            if (s.charAt(i) == '(') {
//                count++;
//            } else if (s.charAt(i) == ')') {
//                count--;
//            }
//            if (count < 0) {
//                toBeRemoved[i] = true;
//                count = 0;
//            }
//        }
//        StringBuilder sb = new StringBuilder();
//        for (int i = n - 1; i >= 0; i--) {
//            if (toBeRemoved[i]) {
//                continue;
//            }
//            if (s.charAt(i) == '(' && count > 0) {
//                count--;
//                continue;
//            }
//            sb.append(s.charAt(i));
//        }
//        return sb.reverse().toString();
//        count = 0;
//        for (int i = n - 1; i >= 0; i--) {
//            if (toBeRemoved[i]) {
//                continue;
//            }
//            if (s.charAt(i) == ')') {
//                count++;
//            } else if (s.charAt(i) == '(') {
//                count--;
//            }
//            if (count < 0) {
//                toBeRemoved[i] = true;
//                count = 0;
//            }
//        }
//        StringBuilder sb = new StringBuilder();
//        for (int i = 0; i < n; i++) {
//            if (!toBeRemoved[i]) {
//                sb.append(s.charAt(i));
//            }
//        }
//        return sb.toString();
    }


    public static void main(String[] args) {
        System.out.println(new RemoveParentheses().remove("(()()("));
        System.out.println(new RemoveParentheses().remove("))))((((("));
        System.out.println(new RemoveParentheses().remove("a((b)c("));
        System.out.println(new RemoveParentheses().remove("()))(()())"));
    }

}
