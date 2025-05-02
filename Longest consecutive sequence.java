class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> hash = new HashSet<>();
        for(int i=0; i<nums.length; i++){
            hash.add(nums[i]);
        }
        int maxlen = 0;
        for(int num: hash){
            if(!hash.contains(num-1)){
                int currLength = 1;
                int curr = num;
                while(hash.contains(curr+1)){
                    curr++;
                    currLength++;
                }
                maxlen = Math.max(maxlen, currLength);
            }
            
        }
        return maxlen;
    }
}
