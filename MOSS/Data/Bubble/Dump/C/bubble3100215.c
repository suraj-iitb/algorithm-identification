#include<stdio.h>

int main()
{
    int n,cnt=0,box;
    scanf("%d",&n);
    int A[n];
    for(int x=0;x<n;x++){
        scanf("%d",&A[x]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[j] < A[j-1]){
                box = A[j];
                A[j] = A[j-1];
                A[j-1] = box;
                cnt +=1;
            }
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
