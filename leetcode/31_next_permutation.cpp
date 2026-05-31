#include <iostream>

using namespace std;

void print_vector(vector<int>& nums){
    cout << "Array => ";
    for(int num:nums){
        cout << num << " ";
    }
    cout << "\n";
}

// to find the next permutation of an array i.e lexi-order
// Next lexicographic permutation algorithm
// Given a permutation:
// Find largest k such that:
// a[k]<a[k+1]
// If none exists, this is the last permutation.
// Find largest l>k such that:
// a[k]<a[l]
// Swap a[k] and a[l].
// Reverse suffix from k+1 to end.
void swap(int i,int j,vector<int>& nums){
    int temp = nums[j];
    nums[j] = nums[i];
    nums[i] = temp;
}
void reverse(int i,int j,vector<int>& nums){
    while(j>i){
        swap(i,j,nums);
        i++;
        j--;
    }
}
void next_permutation(vector<int>& nums){
    int n = nums.size();
    int i = n - 2;
    while(i>=0 && nums[i] >= nums[i+1]){
        i--;
    }
    if(i<0) {
        reverse(0,n-1,nums);
        return;
    }
    int j=n-1;
    for(;j>i;j--){
        if(nums[j]>nums[i]) break;
    }
    cout << i << "  " << j;
    swap(i,j,nums);
    reverse(i+1,n-1,nums);

}




int main(){
    int n;
    cout << "Enter an odd Integer greater than 0: ";
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    next_permutation(nums);
    print_vector(nums);

}