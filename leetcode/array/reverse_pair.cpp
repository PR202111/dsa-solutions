#include <iostream>
#include <vector>

using namespace std;

int merge_and_compare(vector<int>& nums,int l,int mid,int r){
    int ans = 0;
    int left_len = mid-l+1;
    int right_len = r - mid;
    vector<int> left(left_len);
    vector<int> right(right_len);
    for(int i=0;i < left_len;i++){
        left[i] = nums[l+i];
    }
    for(int i=0;i< right_len;i++){
        right[i] = nums[mid+i+1];
    }
    int j = 0;
    for(int i=0;i<left_len;i++){
        
        while(j<right_len && (long long)left[i] > 2*(long long)right[j]){
            j++;
        }
        ans += j;
    }
    
    for(int k=l,i=0,j=0;k<=r;k++){
        if(j>=right_len || (i<left_len && left[i]<right[j])){
            nums[k] = left[i];
            i++;
        }
        else{
            nums[k] = right[j];
            j++;
        }
    }
    

    return ans;
}
int divide(vector<int>& nums,int l,int r){
    if(r>l){
        int mid = l+(r-l)/2;
        int ans1 = divide(nums,l,mid);
        int ans2 = divide(nums,mid+1,r);

        return ans1+ans2 + merge_and_compare(nums,l,mid,r);
    }

    return 0;
}
int reversePairs(vector<int>& nums) {
    int n = nums.size();
    if(n <= 1){
        return 0;
    }
    return divide(nums,0,nums.size()-1);
    
}

int main(){
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0;i<n;i++){
        cin >> nums[i];
    }

    cout << "Reverse Pair" << reversePairs(nums);


    return 0;
}