#include <stdio.h>
#include <stdlib.h>

void sSort(int *,int);

int c=0;

int main(){
    int p,num[100],i;

    scanf("%d",&p);
    if(p<1&&p>100) exit(1);
    for(i=0;i<p;i++){
        scanf("%d",&num[i]);
    }
    
    sSort(num,p);

    for(i=0;i<p-1;i++){
        printf("%d ",num[i]);
    }
    printf("%d\n",num[p-1]);
    printf("%d\n",c);
    return 0;
}

void sSort(int *A,int N){
    int i,j,minj,T;

    for(i=0;i<N;i++){
        minj = i;
        for(j=i;j<N;j++){
            if(A[j]<A[minj]){
                minj=j;
            }
        }
        if(i==minj) continue;
                T=A[i];
                A[i]=A[minj];
                A[minj]=T;
                c++;
        
    }
}
    
