
class Solution {

    void helper(int ind, int sc, int arrows, int &mxsc, vector<int> &arr, vector<int> &psf, vector<int> &res){
        if(arrows == 0 || ind >= 12){
            if(sc >= mxsc){
                mxsc = sc;
                res = psf;
            }
            return ;
        }

        helper(ind+1, sc, arrows, mxsc, arr, psf, res);
        if(arrows > arr[ind]){
            psf[ind] = arr[ind]+1;
            helper(ind+1, sc+ind, arrows-arr[ind]-1, mxsc, arr, psf, res);
            psf[ind] = 0;
        }

    }

public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> psf(12, 0);
        vector<int> res;
        int mxsc = 0;
        

        helper(0, 0, numArrows, mxsc, aliceArrows, psf, res);
        int sm = 0;
        for(auto el : res){
            sm += el;
        }
        res[0] += max(0, numArrows-sm);

        return res;
    }
};