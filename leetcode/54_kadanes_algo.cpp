#include <iostream>

using namespace std;


// to find maximum of a subaaray we will use kadanes algorithm
int max_subaray(vector<int>& nums){
    int ans = nums[0];
    int running_sum = 0;
    for(int num:nums){
        running_sum += num;
        running_sum = max(running_sum,num);
        ans = max(ans,running_sum);
        
    }

    return ans;
}




int main(){
    int n;
    cout << "Enter an odd Integer greater than 0: ";
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    
    cout << max_subaray(nums) << "\n";

}