#include <iostream>

using namespace std;

int minimum(vector<int>& nums){
    int l=0;
    int r = nums.size()-1;
    while(r>l){
        int mid = l+(r-l)/2;
        if(nums[mid] <= nums[r]){
            r = mid;
        }
        else l = mid+1;
    }

    return nums[l];
}

int main(){
    int n;
    cout << "Enter an odd Integer greater than 0: ";
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    

    cout << "minimum: " << minimum(nums);
    cout << "\n";
    
    return 0;
}