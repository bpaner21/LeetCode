class Solution {
    public List<String> buildArray(int[] target, int n) {
        
        ArrayList<String> stack = new ArrayList<>();
        
        int currentNum = 1;
        
        for (int i = 0; i < target.length; ++i) {
            
            while (currentNum != target[i]) {
                
                stack.add("Push");
                stack.add("Pop");
                ++currentNum;
            }
            
            stack.add("Push");
            ++currentNum;
        }
        
        return stack;
    }
}