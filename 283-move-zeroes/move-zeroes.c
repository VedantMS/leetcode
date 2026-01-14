void moveZeroes(int* nums, int numsSize) {
    int index = 0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] != 0) {
            int temp = nums[i];
            nums[i] = nums[index];
            nums[index++] = temp;
        }
    }
}