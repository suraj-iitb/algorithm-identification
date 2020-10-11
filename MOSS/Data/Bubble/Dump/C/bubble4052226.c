#include <stdio.h>
#define MAX 100
int main(){
  int num[MAX],a,i,j,k,m,n=0;
    scanf("%d",&a);
    for(i=0;i<a;i++){
        scanf("%d",&num[i]);
    }
    for(j=1;j<a;j++){
        i=j;
        for(k=j-1;k>=0;k--){
            if(num[k]>num[i]){
                m=num[k];
                num[k]=num[i];
                num[i]=m;
                i--;
                n++;
            }
        }
    }
       for(i=0;i<a;i++){
       printf("%d",num[i]);
       if(i !=a-1){
           printf(" ");
       }
       }
    printf("\n%d\n",n);
    return 0;
}

