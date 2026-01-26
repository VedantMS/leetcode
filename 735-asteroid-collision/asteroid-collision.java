class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> st = new Stack<>();
        for(int i : asteroids) {
            if(st.isEmpty()) {
                st.push(i);
            }
            else {
                boolean destroyed = false;
                while(!st.isEmpty() && st.peek() > 0 && i < 0) {
                    if(st.peek() < Math.abs(i)) {
                        st.pop();
                        continue;
                    }
                    else if(st.peek() == Math.abs(i)) {
                        st.pop();
                    }
                    destroyed = true;
                    break;
                }
                if(!destroyed) {
                    st.push(i);
                }
            }
        }
        int[] result = new int[st.size()];
        for(int i = result.length - 1; i >= 0 ; i--) {
            result[i] = st.pop();
        }
        return result;
    }
}