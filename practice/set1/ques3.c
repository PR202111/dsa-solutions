#include<stdio.h>
int main(){
    int n;
    printf("Enter the size of Array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the Elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int k;
    printf("Enter the number of left shifts: ");
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int last = arr[n-1];
        for(int j=n-1;j>0;j--){
            arr[j] = arr[j-1];
        }
        arr[0] = last;
    }

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}