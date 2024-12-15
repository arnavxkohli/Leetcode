import java.util.PriorityQueue;

class HeapEntry {
    private int index;
    private double pass;
    private double total;

    public HeapEntry(int _index, double _pass, double _total) {
        this.index = _index;
        this.pass = _pass;
        this.total = _total;
    }

    // Prioritize the class that gives us the most gain from adding a passing student to it
    public double getGain() {
        return ((pass+1)/(total+1)) - ((pass)/(total));
    }

    public double getRatio() {
        return pass/total;
    }

    public void addStudent() {
        pass++; total++;
    }

    public int getIndex() {
        return index;
    }
}


class Solution {
    public double maxAverageRatio(int[][] classes, int extraStudents) {

        // Order to maximize the priority, so this is a max heap. Order of a and b matters here (max vs min heap)
        PriorityQueue<HeapEntry> ratioHeap = new PriorityQueue<>(
            (a, b) -> Double.compare(b.getGain(), a.getGain())
        );

        for(int index = 0; index < classes.length; index++) {
            int[] _class = classes[index];
            double pass = (double) _class[0], total = (double) _class[1];
            HeapEntry curr = new HeapEntry(index, pass, total);
            ratioHeap.add(curr);
        }

        // Pick the student with the highest gain and increment their pass number and total number
        while (extraStudents > 0) {
            HeapEntry lowestHeapEntry = ratioHeap.poll();
            lowestHeapEntry.addStudent();
            ratioHeap.add(lowestHeapEntry);
            extraStudents--;
        }

        double totalAverage = 0.0;
        while(!ratioHeap.isEmpty()) {
            totalAverage += ratioHeap.poll().getRatio();
        }

        return totalAverage/classes.length;
    }
}

public class Main {

    public static void main(String[] args) {
        System.out.println("Hi");
    }
}