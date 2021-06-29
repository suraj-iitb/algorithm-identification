#include <stdio.h>
#include <stdlib.h>

int Bubblesort(int ,int *);

int main(){
    int n,i;
    int *buffer;
    int cnt;

    scanf("%d",&n);
    buffer = (int *)malloc(sizeof(int) * n);

    for(i=0;i<n;i++){
        scanf("%d",&buffer[i]);
    }

    cnt = Bubblesort(n,buffer);

    for(i=0;i<n;i++){
        if(i==n-1)printf("%d\n",buffer[i]);
        else printf("%d ",buffer[i]);
    }
    printf("%d\n",cnt);

    return 0;
}

int Bubblesort(int n,int *A){
    int cnt=0,i,j;
    int tmp;

    for(i=0;i<n;i++){
        for(j=n-1;j>=i+1;j--){
            if(A[j] < A[j-1]){
                tmp=A[j];
                A[j]=A[j-1];
                A[j-1]=tmp;
                cnt++;
            }
        }
    }
    return cnt;
}
