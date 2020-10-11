#include <stdio.h>

int main(void)
{
    int i,j,n,tmp,A[1000];
   scanf("%d",&n);
   for(i=0;i<n;i++){
    scanf("%d",&A[i]);
   }

        
        for(j=0;j<n;++j){
   
            for(i=j; i!=0 && A[i]<A[i-1] ;--i){
             
                tmp=A[i-1];
                A[i-1]=A[i];
                A[i]=tmp;
            }
              for(i=0;i<n;++i){
                if(i>0)printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
        }
    return 0;
}
