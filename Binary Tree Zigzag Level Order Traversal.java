
class Solution {

    private int height(TreeNode root){
    if(root==null) return 0;
    int leftHeight = height(root.left);
    int rightHeight = height(root.right);
    return Math.max(leftHeight, rightHeight)+1;
}

private void leftToRight(TreeNode root, int level, List<Integer> list){
    if(root==null) return;
    if(level==1){
        list.add(root.val);
    }else{
        leftToRight(root.left, level-1,list);
        leftToRight(root.right, level-1,list);
    }
}

private void rightToLeft(TreeNode root, int level, List<Integer> list ){
    if(root==null) return;
    if(level==1){
        list.add(root.val);
    }else{
        rightToLeft(root.right, level-1,list);
        rightToLeft(root.left, level-1,list);
    }
}


    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        int count = height(root);
        List<List<Integer>> result = new ArrayList<>();
        boolean l2h = true;
    for(int i=1; i<=count; i++){
        List<Integer> current = new ArrayList<>();
        if(l2h){
            leftToRight(root,i,current);
        }else{
            rightToLeft(root,i,current);
        }
        l2h = !l2h;
        result.add(current);
    }
    return result;
    }
}
