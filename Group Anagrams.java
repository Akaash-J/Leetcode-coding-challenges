class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        if(strs==null || strs.length==0) return null;
        Map<Double,List<String>> map = new HashMap<>();
        int[] nos = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
        for(String word: strs){
            double prod =1;
            for(int i=0; i<word.length(); i++){
                prod*=nos[word.charAt(i)-'a'];
            }
            if(map.containsKey(prod)){
                map.get(prod).add(word);
            }else{
                map.put(prod, new ArrayList<String>());
                map.get(prod).add(word);
            }
        }
        List<List<String>> result = new ArrayList<List<String>>();
        for(List<String> val :map.values()){
            result.add(val);
        }
        return result;
    }
}
