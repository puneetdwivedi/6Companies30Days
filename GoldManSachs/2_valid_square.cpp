class Solution {

    double calculateDistance(vector<int> &p1, vector<int> &p2){
        int x2 = (p2[0]-p1[0])*(p2[0]-p1[0]);
        int y2 = (p2[1]-p1[1])*(p2[1]-p1[1]);
        x2 += y2;
        return sqrt(x2);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<double,int> mp;
        mp[calculateDistance(p1, p2)]++;
        mp[calculateDistance(p1, p3)]++;
        mp[calculateDistance(p1, p4)]++;
        mp[calculateDistance(p2, p3)]++;
        mp[calculateDistance(p2, p4)]++;
        mp[calculateDistance(p3, p4)]++;

        if(mp.size() != 2) return false;
        bool have4 = false;
        bool have2 = false;
        for(auto el : mp){
            if(el.second == 4 && el.first != 0){
                have4 = true;
            }
            else if(el.second == 2 && el.first != 0){
                have2 = true;
            }
        }

        return have4 && have2;
    }
};