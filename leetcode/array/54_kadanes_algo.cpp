#include <iostream>

using namespace std;


// to find maximum of a subaaray we will use kadanes algorithm for sum we can do the same for the product also
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

int max_subarray_product(vector<int>& nums){
    int ans = 0;
    int n = nums.size();
    int l = 1;
    int r = 1;
    for(int i=0;i<n;i++){
        l *= nums[i];
        r *= nums[n-i-1];
        ans = max(ans,max(l,r));
        if(l==0) l=1;
        if(r==0) r=1;
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
    
    cout << max_subarray_product(nums) << "\n";

}