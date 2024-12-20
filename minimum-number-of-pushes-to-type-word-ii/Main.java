import java.util.*;

class Solution {
    public int minimumPushes(String word) {
        HashMap<Character, Integer> frequencyMap = new HashMap<>();
        for(char c : word.toCharArray()) {
            frequencyMap.put(c, frequencyMap.getOrDefault(c, 0) + 1);
        }

        ArrayList<Map.Entry<Character, Integer>> frequencyList = new ArrayList<>(frequencyMap.entrySet());
        frequencyList.sort(
            (a, b) -> b.getValue() - a.getValue()
        );

        int entryCount = 0;
        for(Map.Entry<Character, Integer> entry : frequencyList) {
            frequencyMap.put(entry.getKey(), (entryCount / 8) + 1);
            entryCount++;
        }

        int pushes = 0;
        for(char c : word.toCharArray()) {
            pushes += frequencyMap.get(c);
        }
        return pushes;
    }
}

public class Main {
    public static void main(String[] args) {  }
}