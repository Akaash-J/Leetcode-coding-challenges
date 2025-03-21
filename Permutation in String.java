class Solution {
    public boolean checkInclusion(String s1, String s2) {
        Map<Character,Integer> need = new HashMap<>();
        Map<Character,Integer> have = new HashMap<>();
        for(int i=0; i<s1.length(); i++){
            char ch = s1.charAt(i);
            need.put(ch,need.getOrDefault(ch,0)+1);
        }
        int start=0,end=0;
        while(end<s2.length()){
            char ch = s2.charAt(end);
            if(!need.containsKey(ch)){
                end++;
                start = end;
                have.clear();
                continue;
            }

            

            have.put(ch,have.getOrDefault(ch,0)+1);

            if(have.get(ch)>need.get(ch)){
                char ch2 = s2.charAt(start);
                have.put(ch2,have.get(ch2)-1);
                if (have.get(ch2) == 0) {
                    have.remove(ch2);
                }
                start+=1;
            }
            int windowSize = end-start+1;
            if(windowSize==s1.length()){
                return true;
            }
            end++;
        }
        return false;
    }
}
