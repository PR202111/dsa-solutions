int isPalindrome(int i,int j,string s){
    while(j>=i){
        if(s[j] != s[i]){
            return 0;
        }
        i++;
        j--;
    }

    return 1;
}
string longestPalindrome(string s) {
    vector<vector<int>> look_up(s.length(),vector<int>(s.length(),0));
    int s_i = -1;
    int s_j = -1;
    for(int i=s.length()-1;i>=0;i--){
        for(int j=i;j<s.length();j++){
            int pal = false;
            if(i == j){
                pal = true;
            }
            else if(j == i + 1 && s[i]==s[j]){
                pal = true;
            }
            else if(s[i]==s[j] && look_up[i+1][j-1]){
                pal = true;
            }

            if(pal){
                look_up[i][j] = true;
                if(j-i>=s_j-s_i){
                    s_j = j;
                    s_i = i;
                }
            }

            
        }
    }

    return s.substr(s_i,s_j-s_i+1);
}