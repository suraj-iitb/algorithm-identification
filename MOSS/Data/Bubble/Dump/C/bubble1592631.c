#include<stdio.h>
int BubbleSort(int *A,int n,int *cnt);
int main(void){
    int n,i;
    int A[128];
    int cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    BubbleSort(A,n,&cnt);
    for(i=0;i<n-1;i++)
        printf("%d ",A[i]);
    printf("%d\n",A[n-1]);
    printf("%d\n",cnt);
    return 0;
}
int BubbleSort(int *A,int n,int *cnt){
    int flag=1;
    int j;
    while(flag){
        flag=0;
        for(j=n-1;j>=1;j--){
            if(A[j]<A[j-1]){
                int temp=A[j];
                A[j]=A[j-1];
                A[j-1]=temp;
                *cnt=*cnt+1;
                flag=1;
            }
        }
    }
}
