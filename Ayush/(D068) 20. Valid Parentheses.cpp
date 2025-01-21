class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i =0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i] == '[') st.push(s[i]); 
            else {
                if(st.size()==0) return false;
                // remove closed bracket
                char ch = st.top();
                st.pop();
                if((s[i]==')' && ch=='(') or 
                    (s[i]==']' && ch=='[') or (s[i]=='}' && ch=='{')) continue;
                else return false;
            }
        }
        return st.empty();
    }
};