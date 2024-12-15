import java.util.HashMap;

class FindSumPairs {
    private int[] _nums2;
    private int[] _nums1;
    private HashMap<Integer, Integer> _frequencies;

    public FindSumPairs(int[] nums1, int[] nums2) {
        this._nums1 = nums1;
        this._nums2 = nums2;
        this._frequencies = new HashMap<>();

        for (int num : this._nums2) {
            this._frequencies.put(num, this._frequencies.getOrDefault(num, 0) + 1);
        }
    }

    public void add(int index, int val) {
        int oldVal = this._nums2[index];
        this._frequencies.put(oldVal, this._frequencies.get(oldVal) - 1);

        int newVal = this._nums2[index] + val;
        this._nums2[index] = newVal;
        this._frequencies.put(newVal, this._frequencies.getOrDefault(newVal, 0) + 1);
    }

    public int count(int tot) {
        int count = 0;

        for(int num: this._nums1) {
            count += this._frequencies.getOrDefault(tot - num, 0);
        }

        return count;
    }
}


public class Main {
    public static void main(String[] args) {
        System.out.println("Hi");
    }
}