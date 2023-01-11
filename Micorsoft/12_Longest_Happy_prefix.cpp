class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> index(n);
        int i = 0;
        int j = 1;
        while(j < n){
            if(s[i] == s[j]){
                index[j] = i+1;
                i++;
                j++;
            }
            else{
                if(i == 0){
                    index[j] = 0;
                    j++;
                }
                else{
                    i = index[i-1];
                }
            }
        }
        // for(auto el: index) cout << el << " ";
        return s.substr(0, index[n-1]);
    }
};