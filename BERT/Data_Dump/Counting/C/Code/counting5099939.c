#include<stdio.h>
#define MAX 2000000
 int B[MAX],A[MAX],n;

int main (){
    int j,i;
    int max=0,kei=0;
   

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
        if(max<A[i])max=A[i];
    
    }
    for(i=0;i<=max;i++){
        B[i]=0;
    }
    for(i=0;i<n;i++){
        B[A[i]]++;
    }
    for(i=0;i<=max;i++){
        if(B[i]>0){
        for(j=1;j<=B[i];j++){
        if(kei!=n-1)printf("%d ",i);
        else printf("%d\n",i);
        kei++;
        }
        }
    }

    return 0;
}

