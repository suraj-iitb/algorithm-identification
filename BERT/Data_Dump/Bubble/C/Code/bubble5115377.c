#include<stdio.h>
#define N 100

int bubbleSort(int *,int);

int main(){
    int i,n,A[N],cnt;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
        cnt=bubbleSort(A,n);
        for(i=0;i<n;i++){
            if(i)printf(" ");
            printf("%d",A[i]);
        }
        printf("\n%d\n",cnt);
        return 0;
}

int bubbleSort(int *A,int n){
    int i,j,flag,v,cnt=0;
    flag=1;
    j=0;
    while(flag){
        flag=0;
        for(i=n-1;i>j;i--){
            if(A[i]<A[i-1]){
                v=A[i];
                A[i]=A[i-1];
                A[i-1]=v;
                flag=1;
                cnt++;
            }
        }
        j++;
    }
    return cnt;
}
