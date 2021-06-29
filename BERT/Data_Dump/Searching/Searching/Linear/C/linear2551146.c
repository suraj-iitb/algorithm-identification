//?????¢??¢?´¢
#include <stdio.h>

int Linear(int A[],int n,int key){
    int i=0;
    A[n]=key;
    while(A[i] != key) i++;
    return i != n;
}

int main(void){
    int i=0,n,A[10001],key;
    int q,sum=0;
    scanf("%d",&n);

    for(i=0;i<n;i++) scanf("%d",&A[i]);
    scanf("%d",&q);

    for(i=0;i<q;i++){
        scanf("%d",&key);
        if(Linear(A, n, key)) sum++;
    }
    printf("%d\n",sum);
}
