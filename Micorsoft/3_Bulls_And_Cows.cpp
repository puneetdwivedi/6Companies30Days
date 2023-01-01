class Solution {
public:
    string getHint(string secret, string guess) {
        int x = 0;
        int n = secret.size();
        map<char,int> mp;

        for(int i = 0; i < n; i++){
            
            if(secret[i] == guess[i]) x++;
            else mp[secret[i]]++;
        }
        int y = 0;
        for(int i = 0; i < n; i++){
            if(secret[i] != guess[i]){
                if(mp.find(guess[i]) != mp.end()){
                   y++;
                    mp[guess[i]]--;
                    if(mp[guess[i]] == 0) mp.erase(guess[i]);
                }
            }
        }

        string ans ="";
        ans.append(to_string(x));
        ans.push_back('A');
        ans.append(to_string(y));
        ans.push_back('B');

        return ans;
    }
};