#include<stdio.h>
int sort(int A[],int n){
    int i,j,tmp;
    int k=0;
    int minj;
    for(i=0;i<n-1;i++){
        minj=i;
        for(j=i;j<=n-1;j++){
        if(A[j]<A[minj])
            minj=j;
        }
        tmp=A[i];
        A[i]=A[minj];
        A[minj]=tmp;
        if(i!=minj)k++;
    }
    return k;
}

int main(){
    int A[100];
    int n,i,k;
    scanf("%d",&n);
    for(i=0;i<n;i++){
    scanf ("%d",&A[i]);
    }
    k=sort(A,n);
    for(i=0;i<n;i++){
        if(i>0){
            printf(" ");
        }
        printf("%d",A[i]);
    }
    printf("\n");
    printf("%d\n",k);
    return 0;
}
