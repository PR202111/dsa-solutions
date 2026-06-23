

// here we are supposed to remove k digits from a string and make a smaller digit 
// so the intution is like kepping the smaller digit in from and removing the larger k
// ones from starting


string removeKdigits(string num, int k) {
    if(k >= num.length()) return "0";
    stack<char> st;
    for(int i=0;i<num.length();i++){
        while(!st.empty() && k>0 && num[i] < st.top()){
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    while(!st.empty() && k>0){
        st.pop();
        k--;
    }
    string ans="";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    int j=0;
    while(j<ans.length() && ans[j]=='0')j++;
    ans = string(ans.begin()+j,ans.end());
    if(ans == "") return "0";

    return ans;
}