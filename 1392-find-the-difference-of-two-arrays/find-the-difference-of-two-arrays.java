class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        HashSet<Integer> a = new HashSet<Integer>();
        HashSet<Integer> b = new HashSet<Integer>();
        for(int num : nums1) {
            a.add(num);
        }
        for(int num : nums2) {
            b.add(num);
        }
        ArrayList<Integer> a1 = new ArrayList<Integer>();
        ArrayList<Integer> b1 = new ArrayList<Integer>();
        for(int num : a) {
            if(!b.contains(num)) {
                a1.add(num);
            }
        }
        for(int num : b) {
            if(!a.contains(num)) {
                b1.add(num);
            }
        }
        return Arrays.asList(a1, b1);
    }
}