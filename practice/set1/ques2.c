#include<stdio.h>
int main(){
    int n;
    printf("Enter the Number of Question:");
    scanf("%d",&n);
    char choice[n];
    int count[4];
    for(int i=0;i<4;i++)count[i]=0;
    printf("Enter the choices for %d Questions\n",n);
    for(int i=0;i<n;i++){
        scanf(" %c",&choice[i]);
        if(choice[i] == 'A'){
            count[0]++;
        }
        else if(choice[i] == 'B'){
            count[1]++;
        }
        else if(choice[i] == 'C'){
            count[2]++;
        }
        else if(choice[i] == 'D'){
            count[3]++;
        }
    }
    int max = 0;
    for(int i=1;i<=3;i++){
        //printf("%d ",count[i]);
        if(count[i]>count[max]) max = i;
    }
    //printf("\n");
    
    printf("Most frequent choice: %c\n",'A'+max);

    return 0;
}