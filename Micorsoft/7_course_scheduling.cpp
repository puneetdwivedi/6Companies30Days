class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n,0);

        for(auto &el : prerequisites){
            graph[el[0]].push_back(el[1]);
            indegree[el[1]]++;
        }
        

        queue <int> q;
        // q.push(0);
        for(int i= 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int>  done;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            done.push_back(node);
            for(auto child : graph[node]){
                indegree[child]--;
                if(indegree[child] == 0){
                    q.push(child);
                }
            }
        }
        
        if(n == done.size()) return true;
        return false;
        
    }
};