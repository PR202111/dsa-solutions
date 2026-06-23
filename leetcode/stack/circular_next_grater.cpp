#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> ans(nums.size(),-1);

        for(int i=2*nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[i%nums.size()] >= st.top()){
                st.pop();
            }

            if(!st.empty()){
                ans[i%nums.size()] = st.top();
            }

            st.push(nums[i%nums.size()]);
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {1,2,1};
    Solution s;
    auto ans = s.nextGreaterElements(nums);

    for(int x : ans) cout << x << " ";
}