#include<stdio.h>
#define N 2000000
#define MAX 100000
void Counting(int *, int *, int);
int a;

int main(){
    int i,A[N];

    scanf("%d",&a);
    for(i = 1;i <= a;i++){
        scanf("%d",&A[i]);
    }
    int B[a];
    Counting(A,B,MAX);

    for(i = 1;i <= a;i++){
        if(i == a)printf("%d\n",B[i]);
        else printf("%d ",B[i]);
    }
    return 0;
}
void Counting(int *A, int *B,int k)
{
    int C[k],i,j;
    for(i = 0;i < k;i++){
        C[i] = 0;
    }
    for(j = 1;j <= a;j++){
        C[A[j]]++;
    }
    for(i = 1;i <= k;i++){
        C[i] += C[i - 1];
    }
    for(j = a;j >= 1;j--){
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
}
