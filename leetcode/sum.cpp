#include <iostream>
using namespace std;

vector<vector<int>> three_sum(vector<int>& nums){
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(),nums.end());
    for(int i=0;i<n-2;i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        int l = i+1;
        int r = n-1;
        while(r>l){
            int sum = nums[i]+nums[l]+nums[r];
            if(sum == 0){
                ans.push_back({nums[i],nums[l],nums[r]});
                while(l<r && nums[l] == nums[l+1]) l++;
                while(l<r && nums[r] == nums[r-1]) r--;
                l++;
                r--;
            }
            else if(sum > 0) r--;
            else l++;
        }
    }

    return ans;
}

vector<vector<int>> four_sum(vector<int>& nums,int target){
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    int n = nums.size();
    for(int i=0;i<n-3;i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        for(int j=i+1;j<n-2;j++){
            if(j>i+1 && nums[j] == nums[j-1]) continue;
            int l = j+1;
            int r = n-1;
            while(r>l){
                int sum = nums[i]+nums[j]+nums[l]+nums[r];
                if(sum ==target){
                    ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                    while(r>l && nums[l] == nums[l+1])l++;
                    while(r>l && nums[r] == nums[r-1])r--;

                    l++;
                    r--;
                }
                else if(sum > target){
                    r--;
                }
                else l++;
                }
        }
    }

    return ans;
}
int main(){
    int n;
    cout << "Enter the size of Array: ";
    vector<int> nums(n);
    cout << "Enter the values in array: \n";
    for(int i=0;i<n;i++){
        cin >> nums[i];
    } 



}