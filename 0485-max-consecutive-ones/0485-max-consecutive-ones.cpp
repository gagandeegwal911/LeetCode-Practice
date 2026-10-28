class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, ans = 0;
        for(int x : nums) {
            count = (x == 1) ? count + 1 : 0;
            ans = max(ans, count);
        }
        return ans;
    }
};