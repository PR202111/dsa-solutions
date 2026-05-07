#include<stdio.h>
#include<string.h>

int main(){
    char data[100][3][50];
    char search[50];
    int n;
    printf("Enter the number of Students:");
    scanf("%d",&n);
    for(int i =0;i<n;i++){
        printf("Enter Name:");
        scanf("%s",data[i][0]);
        printf("Enter Roll No:");
        scanf("%s",data[i][1]);
        printf("Enter Department:");
        scanf("%s",data[i][2]);
    }

    
    printf("Enter the student name to search:");
    scanf("%s",search);
    for(int i =0;i<n;i++){
        if(strcmp(data[i][0],search)==0){
            printf("Name: %s Roll No: %s Department: %s\n",data[i][0],data[i][1],data[i][2]);
            return 0;
        }
    }
    
    printf("Not found\n");
    
    return 0;
}