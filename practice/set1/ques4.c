#include<stdio.h>

int main(){
    int max[100] = {0};
    int data[100][12];
    int total[100] = {0};
    int n;
    printf("Enter the Number of Stores: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter Mothly Sales of %d store: ",i+1);
        for(int j= 0;j<12;j++){
            scanf("%d",&data[i][j]);
            if(max[i]< data[i][j]) max[i] = data[i][j];
            total[i] += data[i][j];
        }
    }
    int row;
    printf("Enter the Row number indexed from 1 to %d: ",n);
    scanf("%d",&row);
    printf("Row: %d, Total Sales: %d, Highest Overall: %d\n",row,total[row-1],max[row-1]);
    return 0;
}