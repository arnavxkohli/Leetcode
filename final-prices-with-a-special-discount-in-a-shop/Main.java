import java.util.Stack;


class Solution {
    public int[] finalPrices(int[] prices) {
        Stack<Integer> stack = new Stack<>();
        for(int i = prices.length - 1; i >= 0; i--) {
            while(!stack.isEmpty() && stack.peek() > prices[i]) {
                stack.pop();
            }
            int discount = stack.isEmpty() ? 0 : stack.peek();
            stack.add(prices[i]);
            prices[i] -= discount;
        }
        return prices;
    }
}

public class Main {
    public static void main(String[] args) {
        System.out.println("Hi");
    }
}