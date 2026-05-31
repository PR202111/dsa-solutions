#include <iostream>

using namespace std;


// this sliding widow approach only works when negative number are not allowed 
// if negative numbers are also allowed then we need prefix sum + hasmap approach
int longest_subaary(vector<int>& nums,int target){
    int max_len = 0;
    int running_sum = 0;
    int n = nums.size();
    int l = 0;
    int r = 0;
    while(r<n){
        running_sum += nums[r];
        
        while(l<r && running_sum > target){
            running_sum -= nums[l++];
        }
        if(running_sum == target){
            max_len = max(r-l+1,max_len);
        }
        r++;
    }

    return max_len;
}

// sum(i,j) = sum(0,j) - sum(0,i) =  target
int longest_subaary_negative(vector<int>& nums,int target){
    int max_len = 0;
    int running_sum = 0;
    unordered_map<int,int> mp;
    
    mp[0] = -1;
    for(int i=0;i<nums.size();i++){
        running_sum += nums[i];
        
        if(mp.find(running_sum-target) != mp.end()){
            max_len = max(max_len,i-mp[running_sum-target]);
        }
        // early prefix are important for maximaum length
        if(mp.find(running_sum) == mp.end()){
            mp[running_sum] = i;
        }

    }

    return max_len;
}

int main(){
    int n;
    cout << "Enter an odd Integer greater than 0: ";
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    cout << "Enter the target: ";
    int target;
    cin >> target;

    cout << longest_subaary_negative(nums,target) << "\n";

}