class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> mp1;

        for(auto el : nums){
            mp1[el]++;
        }

        map<int,int> mp2;

        for(auto el : nums){
            if(mp1[el] == 0) continue;

            if(mp2[el] > 0){
                mp2[el]--;
                mp1[el]--;

                mp2[el+1]++;
            }
            else if(mp1[el] > 0 && mp1[el+1] > 0 && mp1[el+2] > 0){
                mp1[el]--;
                mp1[el+1]--;
                mp1[el+2]--;
                mp2[el+3]++;
            }
            else return false;
        }

        return true;
    }
};