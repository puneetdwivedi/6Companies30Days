class Solution {

    void helper(int ind, int curr,  int sum,  vector<int> &psf, vector<vector<int>> &result){
        
        if(ind == 0){
            if(sum == 0){
                vector<int> tmp;
                result.push_back(psf);
            }
            return ;
        }
        if(curr > 9) return ;
        if(sum <= 0) return ;

        // decide not to take
        helper(ind, curr+1, sum, psf, result);
        // take option
        psf.push_back(curr);
        helper(ind-1, curr+1, sum - curr, psf, result);
        psf.pop_back();
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> result;
        vector<int> psf;
        helper(k, 1, n, psf, result);

        return result;
    }
};