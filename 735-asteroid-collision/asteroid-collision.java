class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        ArrayDeque<Integer> st = new ArrayDeque<>();
        for(int i : asteroids) {
            boolean destroyed = false;
            while(!st.isEmpty() && st.peekLast() > 0 && i < 0) {
                if(st.peekLast() < Math.abs(i)) {
                    st.removeLast();
                    continue;
                }
                else if(st.peekLast() == Math.abs(i)) {
                    st.removeLast();
                }
                destroyed = true;
                break;
            }
            if(!destroyed) {
                st.addLast(i);
            }
        }
        int[] result = new int[st.size()];
        for(int i = 0; i < result.length ; i++) {
            result[i] = st.pollFirst();
        }
        return result;
    }
}