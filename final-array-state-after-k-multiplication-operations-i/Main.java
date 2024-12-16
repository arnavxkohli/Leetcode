import java.util.PriorityQueue;

class HeapElement {
    int num;
    int index;
    private int _multiplier;

    public HeapElement(int num, int index, int multiplier) {
        this.num = num;
        this.index = index;
        this._multiplier = multiplier;
    }

    public void multiply() {
        this.num *= _multiplier;
    }
}

class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        PriorityQueue<HeapElement> pq = new PriorityQueue<>(
            (a, b) -> (a.num == b.num) ? a.index - b.index : a.num - b.num
        );

        for(int i = 0; i < nums.length; i++) {
            HeapElement element = new HeapElement(nums[i], i, multiplier);
            pq.add(element);
        }

        while(k > 0) {
            HeapElement smallest = pq.poll();
            smallest.multiply();
            pq.add(smallest);
            k--;
        }

        int[] result = new int[nums.length];
        while(!pq.isEmpty()) {
            HeapElement curr = pq.poll();
            result[curr.index] = curr.num;
        }

        return result;
    }
}

public class Main {
    public static void main(String[] args) {
        System.out.println("Hi");
    }
}