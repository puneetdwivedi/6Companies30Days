#define ll long long int
const int mod = int(1e9)+7;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n);

        for(auto el : roads){
            graph[el[0]].push_back({el[1], el[2]});
            graph[el[1]].push_back({el[0], el[2]});
        }

        vector<ll> time(n, LONG_MAX);
        vector<ll> ways(n, 0);

        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

        pq.push({0, 0});
        ways[0] = 1;
        time[0] = 0;

        while(!pq.empty()){
            int node = pq.top().second;
            ll currTime = pq.top().first;
            pq.pop();
            for(auto it : graph[node]){
                int adjNode = it.first;
                ll tt = it.second;
                if(currTime+tt < time[adjNode]){
                    time[adjNode] = currTime + tt;
                    pq.push({time[adjNode], adjNode});
                    ways[adjNode] = ways[node] % mod;
                }
                else if(currTime+tt == time[adjNode]){
                    ways[adjNode] = (ways[adjNode]+ways[node])%mod;
                }
            }
        }

        return ways[n-1];
    }
};