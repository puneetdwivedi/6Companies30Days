class Solution {
    long long int calculateDistance(vector<int> &p1, vector<int> &p2){
        long long int x2 = (p2[0]-p1[0])*(p2[0]-p1[0]);
        int y2 = (p2[1]-p1[1])*(p2[1]-p1[1]);
        x2 += y2;
        return (abs(x2));
    }

public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        for(int i = 0; i < n; i++){
            map<long long int,int> mp;
            for(int j = 0; j < n; j++){
                if(i != j){
                    mp[calculateDistance(points[i], points[j])]++;
                }
            }
            // cout << points[i][0] << " " << points[i][0] << " -> ";
            for(auto &el : mp){
                // cout << el.first << " " << el.second << endl;
                 res += (el.second)*(el.second-1);
            }
    
        }

        return res;
    }
};