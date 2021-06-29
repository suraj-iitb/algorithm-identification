#include <stdio.h>
#define MAX 100
int main(){
  int num[MAX],a,i,j,k,m,n;
    scanf("%d",&a);
    for(i=0;i<a;i++){
        scanf("%d",&num[i]);
        printf("%d",num[i]);
        if(i !=a-1){
           printf(" ");
       }
    }
    printf("\n");
    for(j=1;j<a;j++){
        n=j;
        for(k=j-1;k>=0;k--){
            if(num[k]>num[n]){
                m=num[k];
                num[k]=num[n];
                num[n]=m;
                n--;
            }
   }
        for(i=0;i<a;i++){
       printf("%d",num[i]);
       if(i !=a-1){
           printf(" ");
       }
       }
        printf("\n");
    }
    return 0;
}

