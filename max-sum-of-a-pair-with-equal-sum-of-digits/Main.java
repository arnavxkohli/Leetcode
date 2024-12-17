import java.util.HashMap;
import java.util.PriorityQueue;

class CappedMinQueue {
    private PriorityQueue<Integer> _pq;
    private int _capacity;

    public CappedMinQueue(int capacity) {
        this._pq = new PriorityQueue<>();
        this._capacity = capacity;
    }

    public void addElement(int element) {
        if(this._pq.size() < this._capacity) {
            // If not at full capacity add to the min heap
            this._pq.add(element);
        } else {
            // If at full capacity, pop and re-add to it, maintain the top `_capacity` elements
            this._pq.poll();
            this._pq.add(element);
        }
    }

    public int getSum() {
        int sum = 0;
        for(int element : this._pq) { sum += element; }
        return sum;
    }
}



class Solution {
    public int maximumSum(int[] nums) {
        HashMap<Integer, CappedMinQueue> hm = new HashMap<>();
        int maxSum = 0;
        

        return maxSum;
    }
}

public class Main {
    public static void main(String[] args) {
        System.out.println("Hi");
    }
}