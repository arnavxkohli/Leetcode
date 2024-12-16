class Solution {
    public String addSpaces(String s, int[] spaces) {
        StringBuilder newString = new StringBuilder();
        int spacesPtr = 0;

        for(int sIndex = 0; sIndex < s.length(); sIndex++) {
            if (spacesPtr < spaces.length && spaces[spacesPtr] == sIndex) {
                newString.append(" ");
                spacesPtr++;
            }
            newString.append(s.charAt(sIndex));
        }
        return newString.toString();
    }
}

public class Main {
    public static void main(String[] args) {
        System.out.println("Hi");
    }
}
