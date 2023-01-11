class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> hash(n, 0);
        sort(arr.begin(), arr.end());
        int mxind = 0;
        for(int i = 1; i < n; i++){
            hash[i] = i;
            for(int j = 0; j < i; j++){
                if( arr[i]%arr[j] == 0 && 1+dp[j] > dp[i]){
                    dp[i] = 1+dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i] > dp[mxind]) mxind = i;
        }

        vector<int> result;
        result.push_back(arr[mxind]);
        while(hash[mxind] != mxind){
            mxind = hash[mxind];
            result.push_back(arr[mxind]);
        }

         reverse(result.begin(), result.end());
         return result;
    }
};