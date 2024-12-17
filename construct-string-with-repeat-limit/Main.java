import java.util.*;

class Solution {
    public String repeatLimitedString(String s, int repeatLimit) {
        TreeMap<Character, Integer> freqMap = new TreeMap<>(Collections.reverseOrder());
        for (char c : s.toCharArray()) {
            freqMap.put(c, freqMap.getOrDefault(c, 0) + 1);
        }

        StringBuilder result = new StringBuilder();
        char prevChar = '\0';
        int usedCount = 0;

        while (!freqMap.isEmpty()) {
            char currentChar = freqMap.firstKey();

            if (currentChar == prevChar && usedCount == repeatLimit) {
                Map.Entry<Character, Integer> nextEntry = freqMap.higherEntry(currentChar);
                if (nextEntry == null) break;

                char nextChar = nextEntry.getKey();
                result.append(nextChar);

                freqMap.put(nextChar, freqMap.get(nextChar) - 1);
                if (freqMap.get(nextChar) == 0) {
                    freqMap.remove(nextChar);
                }

                prevChar = nextChar;
                usedCount = 1;
            } else {
                result.append(currentChar);
                int remaining = freqMap.get(currentChar) - 1;

                if (remaining == 0) {
                    freqMap.remove(currentChar);
                } else {
                    freqMap.put(currentChar, remaining);
                }

                usedCount = (currentChar == prevChar) ? usedCount + 1 : 1;
                prevChar = currentChar;
            }
        }

        return result.toString();
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.repeatLimitedString("cczazcc", 3)); // Expected: "zzcccac"
    }
}