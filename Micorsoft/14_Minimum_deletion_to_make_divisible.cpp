class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
       int gcd = 0;
       for(auto el : numsDivide){
           gcd = __gcd(gcd, el);
       }

       int x = INT_MAX;
        for(auto el : nums){
            if(gcd%el == 0){
                x = min(el, x);
            }
        }

        if(x == INT_MAX) return -1;
        int cnt = 0;
        for(auto el : nums){
            if(el < x) cnt++;
        }

        return cnt;
    }
};