#include <iostream>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end(), [](const vector<int>& v1,const vector<int>& v2){
        if(v1[0] != v2[0])
            return v1[0] < v2[0];
        
        return v1[1] < v2[1];
    });
    for(int i=0;i<nums.size();i++){
        if(ans.empty() || ans.back()[1] <  nums[i][0] || ans.back()[1] < nums[i][0]){
            ans.push_back(nums[i]);
        }
        else {
            ans.back()[0] = min(ans.back()[0],nums[i][0]);
            ans.back()[1] = max(ans.back()[1],nums[i][1]);
        }
        
    }

    return ans;
}

int main(){
    int n;
    // cin >> n;
    // vector<vector<int>> nums(n,vector<int>(2));
    // for(int i=0;i<n;i++){
    //     cin >> nums[i][0] >> nums[i][1];
    // }



    return 0;
}