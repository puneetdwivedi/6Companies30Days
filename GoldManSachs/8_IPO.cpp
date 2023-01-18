class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> arr;
        for(int i = 0;i < profits.size(); i++){
            arr.push_back({capital[i], profits[i]});
        }
        sort(arr.begin(), arr.end());
        priority_queue<int> pq;

        int n= profits.size();
        for(int i= 0;i  < n; i++){
            if(w >= arr[i].first){
                pq.push(arr[i].second);
            }
            else{
                if(pq.empty() || k == 0) return w;
                auto tp = pq.top();
                w += tp;
                pq.pop(); 
                k--;
                i--;
            }
        }

        while(!pq.empty() && k){
            w += pq.top();
            pq.pop();
            k--;
        }

        return w;
    }
};