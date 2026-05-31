#include <iostream>
using namespace std;

// helper functions
void print_vector(vector<int>& nums){
    cout << "Array => ";
    for(int num:nums){
        cout << num << " ";
    }
    cout << "\n";
}

void swap(int i,int j,vector<int>& nums){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void bubble_sort(vector<int>& nums){
    int n = nums.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(nums[j] > nums[j+1]){
                swap(j,j+1,nums);
            }
        }
    }
}

void bubble_sort_recursive(vector<int>& nums, int n){

    if(n == 1){
        return;
    }
    
    for(int i = 0; i < n - 1; i++){

        if(nums[i] > nums[i + 1]){
            swap(nums[i], nums[i + 1]);
        }
    }
    bubble_sort_recursive(nums, n - 1);
}

void insertion_sort(vector<int>& nums){
    int n = nums.size();
    for(int i=1;i<n;i++){
        int key = nums[i];
        int start = i-1;
        while(start>=0 && nums[start] > key){
            nums[start+1] = nums[start];
            start--;
        }
        nums[start+1] = key;
    }
}

void insertion_sort(vector<int>& nums, int n){

    if(n <= 1){
        return;
    }

    insertion_sort(nums, n - 1);

    
    int last = nums[n - 1];
    int j = n - 2;

    while(j >= 0 && nums[j] > last){
        nums[j + 1] = nums[j];
        j--;
    }

    nums[j + 1] = last;
}

int main(){
    int n;
    cout << "Enter ans Integer greate than 0: ";
    cin >> n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin >> vec[i];
    }
    print_vector(vec);
    insertion_sort(vec);
    print_vector(vec);
    return 0;
}