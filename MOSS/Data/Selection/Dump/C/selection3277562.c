#include <stdio.h>
#define N 100
int main(void){
    int num,i,j,math[N],temp,count=0,min;
    scanf("%d",&num);
    for(i=0;i<num;i++){
        scanf("%d",&math[i]);
    }
    
    for(i=0;i<=num-2;i++){
        min = i;
        for(j=i;j<=num-1;j++){
            if(math[j]<math[min]){
               min = j;
            }
        }
        
       if(i != min ){
            temp =math[min];
            math[min]=math[i];
            math[i]=temp;
            count++;
        }
    }
    
    printf("%d",math[0]);
    for(i=1;i<num;i++){
        printf(" %d",math[i]);
    }
    printf("\n%d\n",count);

    return 0;
}
