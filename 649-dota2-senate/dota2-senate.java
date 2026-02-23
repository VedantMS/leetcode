class Solution {
    public String predictPartyVictory(String senate) {
        int n = senate.length();
        
        Queue<Integer> radiant = new LinkedList<>();
        Queue<Integer> dire = new LinkedList<>();

        for(int i = 0; i < n; i++) {
            if(senate.charAt(i) == 'R')    radiant.add(i);
            else    dire.add(i);
        }

        while(!radiant.isEmpty() && !dire.isEmpty()) {
            if(radiant.peek() > dire.peek())  dire.add(n++);
            else    radiant.add(n++);

            radiant.poll();
            dire.poll();
        }

        if(radiant.isEmpty())     return "Dire";

        return "Radiant";
    }
}