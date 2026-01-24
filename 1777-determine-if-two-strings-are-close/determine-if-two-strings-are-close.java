class Solution {
    public boolean closeStrings(String word1, String word2) {
        TreeMap<Character, Integer> t1 = new TreeMap<>();
        TreeMap<Character, Integer> t2 = new TreeMap<>();
        
        int len1 = word1.length();
        int len2 = word2.length();
        
        if(len1 != len2)    return false;

        for(int i = 0; i < len1; i++) {
            t1.put(word1.charAt(i), t1.getOrDefault(word1.charAt(i), 0) + 1);
            t2.put(word2.charAt(i), t2.getOrDefault(word2.charAt(i), 0) + 1);
        }

        if(!t1.keySet().equals(t2.keySet()))    return false;

        ArrayList<Integer> l1 = new ArrayList<>(t1.values());
        ArrayList<Integer> l2 = new ArrayList<>(t2.values());

        Collections.sort(l1);
        Collections.sort(l2);
        
        return l1.equals(l2);
    }
}