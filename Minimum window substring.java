class Solution {
    public String minWindow(String s, String t) {
        if(s.length()<t.length() || t.length()==0){
            return "";
        }
        int freq[] = new int[128];
        for(char t1: t.toCharArray()){
            freq[t1]++;
        }
        int left=0, right=0;
        int minlen = Integer.MAX_VALUE;
        int start = -1;
        int needed = t.length();
        while(right<s.length()){
            char r = s.charAt(right);
            if(freq[r]>0) needed--;
            freq[r]--;
            right++;
            while(needed==0){
                if(minlen>right-left){
                    minlen = right-left;
                    start = left;
                }
                char l = s.charAt(left);
                freq[l]++;
                if(freq[l]>0) needed++;
                left++;
            } 
        }
        if(minlen==Integer.MAX_VALUE) return "";
        return s.substring(start, start+minlen);
    }
}
