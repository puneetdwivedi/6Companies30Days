class Solution {

    bool rootToNodePath(int node, int prv, int time, int bob, vector<vector<int>> &graph, map<int,int> &bobVisit){
        bobVisit[node] = time;

        if(node == bob){
            return true;
        }

        for(auto el : graph[node]){
            if(el != prv) {
                if(rootToNodePath(el, node, time+1, bob, graph, bobVisit)){
                    return true;
                }
            }
        }

        bobVisit.erase(node);
        return false;
    }

    int maxProfit(int node, int prv, int time, vector<vector<int>> &graph, map<int,int> &bobVisit, vector<int> &amount){
        int res = 0;
        if(bobVisit.find(node) == bobVisit.end()) res += amount[node];
        else if(bobVisit[node] == time){
            res += amount[node]/2;
        }
        else if(bobVisit[node] < time){
            res += 0;
        }
        else{
            res += amount[node];
        }
        vector<int> mx;
        for(auto el : graph[node]){
            if(el != prv){
               mx.push_back(maxProfit(el, node, time+1, graph, bobVisit, amount));
            }
        }

        int m = INT_MIN;
        for(auto el : mx) m = max(m, el);
        if(m == INT_MIN) m = 0; 
        cout <<node << " -> " << m << " " << res << endl;
        return m+res;
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        map<int, int> bobVisit;
        int n = amount.size();
        vector<vector<int>> graph(n);
        for(auto el : edges){
            graph[el[0]].push_back(el[1]);
            graph[el[1]].push_back(el[0]);
        }

        rootToNodePath(0, -1, 1, bob, graph, bobVisit);
        int t = bobVisit.size();
        for(auto &el : bobVisit){
            el.second = t-el.second+1;
            // cout << el.first << " " << el.second << endl;
        }
        int result = maxProfit(0, -1, 1, graph, bobVisit, amount);

        return result;
    }
};