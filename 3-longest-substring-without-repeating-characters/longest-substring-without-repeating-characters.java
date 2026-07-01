class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int[] hash = new int[256];

        // Initialize all values to -1
        for (int i = 0; i < 256; i++) {
            hash[i] = -1;
        }

        int left = 0;
        int maxLen = 0;
        int right=0;
        if(n==0) return 0;
        while(left<=right){
            char ch = s.charAt(right);

            if (hash[ch] != -1 && hash[ch] >= left) {
                left = hash[ch] + 1;
            }

            int len = right - left + 1;
            maxLen = Math.max(maxLen, len);

            hash[ch] = right;
            if(right<n-1){
                right++;
            }
            
        }

        return maxLen;
    }
}