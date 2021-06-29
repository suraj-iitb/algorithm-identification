#include<stdio.h>
void selectionSort(int *A,int n,int *cnt);
int main(void){
    int n,A[128],i,cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    selectionSort(A,n,&cnt);
    for(i=0;i<n-1;i++)
        printf("%d ",A[i]);
    printf("%d\n",A[n-1]);
    printf("%d\n",cnt);
    return 0;
}
void selectionSort(int *A,int n,int *cnt){
    int i,j,minj,temp;
    for(i=0;i<n;i++){
        minj=i;
        for(j=i;j<n;j++)
            if(A[j]<A[minj]){
                minj=j;
            }
        if(minj!=i){
            temp=A[i];
            A[i]=A[minj];
            A[minj]=temp;
            *cnt=*cnt+1;
        }
    }
}
