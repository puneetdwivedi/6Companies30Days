class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        map<char,int> mp;

        int i = 0;
        int j = 0;
        int res  = 0;
        while(i < n){
            if(mp.size() < 3){
                mp[s[i]]++;
                if(mp.size() == 3){
                    res += (n-i);
                }
                i++;
            }
            else{
                while(j < i && mp.size() == 3){
                    mp[s[j]]--;
                    if(mp[s[j]] == 0){
                        mp.erase(s[j]);
                    }
                    else{
                        res+=(n-i+1);
                        cout << (n-i+1) << " ";
                    }
                    
                    j++;
                }
            }
        }

        while(j < i && mp.size() == 3){
            mp[s[j]]--;
            if(mp[s[j]] == 0){
                mp.erase(s[j]);
            }
            else{
                res++;
            }
            j++;
        }
        
        return res;
    }
};