#include <iostream>

using namespace std;
int ceil(vector<int>& nums,int x){
    int ans = INT_MAX;
    int l = 0;
    int r = nums.size();
    while(r>=l){
        int mid = l+(r-l)/2;
        if(nums[mid]>=x){
            ans = nums[mid];
            r = mid-1;
        }
        else l = mid+1;
    }

    return ans;
}
int floor(vector<int>& nums,int x){
    int ans = INT_MIN;
    int l = 0;
    int r = nums.size();
    while(r>=l){
        int mid = l+(r-l)/2;
        if(nums[mid]<=x){
            ans = nums[mid];
            l = mid+1;
        }
        else r= mid-1;
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
    int target;
    cin >> target;

    cout << "Floor: " << floor(nums,target) << " Ceil: " << ceil(nums,target);
    cout << "\n";
    
    return 0;
}