#include <stdio.h>
#define N 100
int main(void){
    int num,i,j,math[N],temp,count=0;
    scanf("%d",&num);
    for(i=0;i<num;i++){
        scanf("%d",&math[i]);
    }
    
    for(i=0;i<num-1;i++){
        for(j=num-1;j>=i+1;j--){
            if(math[j]<math[j-1]){
                temp =math[j-1];
                math[j-1]=math[j];
                math[j]=temp;
                count++;
            }
        }
    }
     printf("%d",math[0]);
    for(i=1;i<num;i++){
        printf(" %d",math[i]);
    }
    printf("\n%d\n",count);
    
    
    return 0;
}

