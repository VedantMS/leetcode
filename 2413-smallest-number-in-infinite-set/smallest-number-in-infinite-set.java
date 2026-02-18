class SmallestInfiniteSet {
    
    boolean[] popped;
    int pointer;
    
    public SmallestInfiniteSet() {
        popped = new boolean[1002];
        pointer = 1;
    }
    
    public int popSmallest() {
        int ans = pointer;
        
        popped[pointer] = true;
        
        while(popped[pointer]) {
            pointer++;
        }
        
        return ans;
    }
    
    public void addBack(int num) {
        popped[num] = false;
        
        if(num < pointer) {
            pointer = num;
        }
    }
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet obj = new SmallestInfiniteSet();
 * int param_1 = obj.popSmallest();
 * obj.addBack(num);
 */