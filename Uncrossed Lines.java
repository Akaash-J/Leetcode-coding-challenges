class Solution {
    public int maxUncrossedLines(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;
        int mat[][] = new int[n1+1][n2+1];
        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                if(nums1[i]==nums2[j]){
                    mat[i+1][j+1] = mat[i][j]+1;
                }else{
                    mat[i+1][j+1] = Math.max(mat[i][j+1], mat[i+1][j]);
                }
            }
        }
        return mat[n1][n2];
    }
}
