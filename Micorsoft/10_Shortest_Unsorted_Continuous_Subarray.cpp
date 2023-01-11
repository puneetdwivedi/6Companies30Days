class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = -1, right = -1;
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for(int i = 0; i < n; i++){
            if(arr[i] != nums[i]){
                left = i;
                break;
            }
        }
        for(int i = n-1; i >=0; i--){
            if(arr[i] != nums[i]){
                right = i;
                break;
            }
        }
        if(left == -1) return 0;
        return right- left + 1;
    }
};