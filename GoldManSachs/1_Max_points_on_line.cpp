class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
       
        int ans = 1;
        for(int i = 0;i <n-1; i++){
             map<double,int> mp;
            for(int j = 0;j < n; j++){
                if(i != j){
                    double x = points[i][0] - points[j][0];
                    double y = points[i][1] - points[j][1];
                    double s = y/x;
                    if(points[j][1]-points[i][1] < 0 && points[i][0]-points[j][0] == 0){
                        mp[abs(s)]++;
                    } 
                    else mp[s]++;
                
                }
            }
            int tmp = 0;
            for(auto el : mp){
                tmp = max(tmp, el.second+1);
            }
            ans =max(ans, tmp);
        }

        return ans;
    }
};