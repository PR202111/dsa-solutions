#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void merge(char arr[][100],int l,int mid,int r){
    int left_len = mid-l+1;
    int right_len = r - mid;
    char left[left_len][100];
    char right[right_len][100];
    for(int i = 0;i<left_len;i++){
        strcpy(left[i],arr[l+i]);
    }
    for(int i = 0;i<right_len;i++){
        strcpy(right[i],arr[mid+i+1]);
    }
    for(int i=0,j=0,k=l;k<=r;k++){
        if(i<left_len && (j>= right_len || strlen(left[i])<=strlen(right[j]))){
            strcpy(arr[k],left[i]);
            i++;
        }
        else{
            strcpy(arr[k],right[j]);
            j++;
        }
    }

}
void divide(char arr[][100],int l,int r){
    if(l<r){
        int mid = l + (r-l)/2;
        divide(arr,l,mid);
        divide(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main(){
    int n;
    printf("Enter the Numner of strings: ");
    scanf("%d",&n);
    char str[n][100];
    for(int i=0;i<n;i++){
        scanf(" %s",str[i]);
    }
    divide(str,0,n-1);
    for(int i=0;i<n;i++){
        printf("%s\n",str[i]);
    }
    return 0;
}