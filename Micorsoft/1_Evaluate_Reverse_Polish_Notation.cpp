class Solution {
    
    
    bool isOperator(string &word){
        if(word == "+" || word == "*" || word == "-" || word == "/") return true;
        return false;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int>  st;
        
        for(auto el : tokens){
            if(isOperator(el)){
                long long int x = st.top();
                st.pop();
                long long int y = st.top();
                st.pop();
                
                if(el == "+"){
                    y += x;
                }
                else if(el == "-"){
                    y -= x;
                }
                else if(el == "*"){
                    y *= x;
                }
                else{
                    y /= x;
                }
                st.push(y);
            }
            else{
                st.push(stoi(el));
            }
        }
        
        return st.top();
    }
};