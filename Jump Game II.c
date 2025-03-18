class Solution {
    public int jump(int[] nums) {
        if(nums.length<=1) return 0;
        int count=0;
        int stepLeft = nums[0];
        int maxReach = nums[0];
        for(int i=1; i<nums.length; i++){
            if(nums.length-1==i) return count+1 ;
            maxReach = (maxReach>nums[i]+i)?maxReach:nums[i]+i;
            stepLeft--;
            if(stepLeft==0){
                count++;
                stepLeft = maxReach-i;
                if(stepLeft<=0) return -1;
            }

            
        }
        return count;
    }
}
