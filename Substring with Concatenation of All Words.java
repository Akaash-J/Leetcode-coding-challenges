class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();

        int wordlength = words[0].length();
        int totalWords = words.length;
        int totalLength = wordlength* totalWords;

        Map<String, Integer> map = new HashMap<>();
        for(String word: words){
            map.put(word,map.getOrDefault(word,0)+1);
        }

        for(int i=0; i<=s.length()-totalLength; i++){
            Map<String, Integer> seen = new HashMap<>();
            int j=0;

            while(j<totalWords){
                int index = i+j*wordlength;
                String word = s.substring(index, index+wordlength);
                if(!map.containsKey(word)) break;
                seen.put(word,seen.getOrDefault(word,0)+1);
                if(seen.get(word) > map.get(word)) break;
                j++;
            }
            if(j==totalWords) result.add(i);
        }

        return result;
    }
}
