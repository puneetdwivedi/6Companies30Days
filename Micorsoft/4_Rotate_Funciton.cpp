class Solution {
public:
    int maxRotateFunction(vector<int>& arr) {
        
        int n = arr.size();

        int original =  0;
        int sm = 0;
        for(int i = 0; i < n; i++){
            sm += arr[i];
            original += (arr[i]*i);
        }

        int result = original;
        for(int i = n-1; i > 0; i--){
            int curr = original + (sm) - (n*arr[i]);
            result = max(result, curr);
            original = curr;
        }

        return result;
    }
};