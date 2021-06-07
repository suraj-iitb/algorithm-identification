#include <stdio.h>
#define N 100000
int main(void){
    int i,j,num1,math1[N],num2,math2[N],h[N],count=0;
    scanf("%d",&num1);
    for(i=0;i<num1;i++){
        scanf("%d",&math1[i]);
    } 
    scanf("%d",&num2);
    for(i=0;i<num2;i++){
        scanf("%d",&math2[i]);
    } 
    
    for(i=0;i<num1;i++){
        for(j=0;j<num2;j++){
            if(math1[i]==math2[j] && h[j]!=1){
                count++;
                h[j]=1;
            }
        }
    }
    printf("%d\n",count);
    
    return 0;
}

