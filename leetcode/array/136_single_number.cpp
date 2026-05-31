#include <iostream>

using namespace std;

// this problem is a nice use of XOR that how it deals with same number
// how to use bit manipulation
int single_number(vector<int>& nums){
    int n = nums.size();
    int ans = 0;
    for(int num:nums){
        ans = ans^num;
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

    cout << single_number(nums) << "\n";

}