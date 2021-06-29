#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int A[n];
    int i,j,tmp;
    int num=0;
    for (i = 0; i < n;i++)
        scanf("%d",&A[i]);

    for (i = 0; i < n;i++)
    {
        for (j = 1; j < n - i;j++)
        {
            if(A[j-1]>A[j])
            {
                tmp = A[j-1];
                A[j-1] = A[j];
                A[j] = tmp;
                num++;
            }
        }
    }
    for (i = 0; i < n - 1; i++)
        printf("%d ",A[i]);
    printf("%d\n%d\n", A[n - 1], num);
    return 0;
}
