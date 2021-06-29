#include <stdio.h>
#include <stdlib.h>

void BSort(int *,int );

int c=0;

int main(){
    int p,num[100],i;

    scanf("%d",&p);
    if(p<1&&p>100) exit(1);
    for(i=0;i<p;i++){
     scanf("%d",&num[i]);
    }
    
    BSort(num,p);

    for(i=0;i<p-1;i++){
     printf("%d ",num[i]);
    }
    printf("%d\n",num[p-1]);
    printf("%d\n",c);
    return 0;
}

void BSort(int *A,int N){
    int F=1,i,T;

   while(F){
       F=0;
       for(i=N-1;i>=1;i--){
        if(A[i]<A[i-1]){
            T=A[i];
            A[i]=A[i-1];
            A[i-1]=T;
            c++;
            F=1;
        }
       }
        
    }
       
}
