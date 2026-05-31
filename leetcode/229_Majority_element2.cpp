#include <iostream>
#include <vector>

using namespace std;

//Boyer–Moore majority vote algorithm
int majority_element_I(vector<int>& nums){
    int n = nums.size();
    int cnt = 0;
    int number = -1;
    for(int num:nums){
        if(cnt == 0){
            number = num;
            cnt = 1;
        }
        else if(num == number) cnt++;
        else cnt--;
    }
    cnt = 0;
    for(int num:nums){
        if(num == number) cnt++;
    }
    if(cnt > n/2){
        return number;
    }

    else return -1;
}
vector<int> majority_element_II(vector<int>& nums){
    vector<int> ans;
    int n = nums.size();
    int cnt1 = 0;
    int cnt2 = 0;
    int number1 = -1,number2 = -1;
    for(int num:nums){
        if(cnt1 == 0 && number2 != num){
            number1 = num;
            cnt1 = 1;
        }
        else if(num == number1) cnt1++;
        else if(cnt2 == 0 && num != number1){
            number2 = num;
            cnt2 = 1;
        }
        else if(num == number2) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0,cnt2=0;
    for(int num:nums){
        if(num == number1) cnt1++;
        else if(num == number2) cnt2++;
    }
    if(cnt1 > n/3){
        ans.push_back(number1);
    }
    if(cnt2 > n/3){
        ans.push_back(number2);
    }

    return ans;
}




int main(){
    int n;
    cout << "Enter the Size of the array: ";
    cin >> n;
    cout << "Enter the Elements of the Arrat\n";
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    cout << majority_element_I(nums) << "\n";


}