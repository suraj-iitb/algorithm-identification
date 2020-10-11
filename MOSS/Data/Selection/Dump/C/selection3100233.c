#include<stdio.h>

int main()
{
    int n,minj,box,cnt = 0;
    scanf("%d",&n);
    int A[n];
    for(int x=0;x<n;x++){
        scanf("%d",&A[x]);
    }
    for(int i=0;i<n;i++){
        minj = i;
        for(int j=i;j<n;j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if(minj != i){
            box = A[i];
            A[i] = A[minj];
            A[minj] = box;
            cnt += 1;
        }
    }
    for(int x=0;x<n;x++){
        if(x != n-1){
            printf("%d ",A[x]);
        }else {
            printf("%d\n",A[x]);
        }
    }
    printf("%d\n",cnt);
    return 0;
}
