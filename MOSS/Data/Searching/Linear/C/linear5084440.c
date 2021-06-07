#include <stdio.h>
int linearSearch(int*,int,int);

int main(){

    int A[100000],B[50000],n,q,i,num=0;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);        
    }

    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&B[i]);
    }

    for(i=0;i<q;i++) {
        num += linearSearch(A,B[i],n);
    }

    printf("%d\n",num);


    return 0;
}

int linearSearch(int *A,int key,int n){
    int j=0;
    A[n] = key;
    while(A[j]!=key){
        j++;
    }
    if(j==n) return 0;
    return 1;

}
