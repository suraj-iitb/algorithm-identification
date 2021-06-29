#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int A[n];
    int i,j,tmp;
    int num=0;
    int mini;
    for (i = 0; i < n;i++)
        scanf("%d",&A[i]);

    for (i = 0; i < n;i++)
    {
        mini = i;
        for (j = i; j < n;j++)
        {
            if(A[j]<A[mini]){
                mini = j;
            }
        }
        if(i!=mini){
            num++;
            tmp = A[i];
            A[i] = A[mini];
            A[mini] = tmp;
        }
    }
    for (i = 0; i < n - 1; i++)
        printf("%d ",A[i]);
    printf("%d\n%d\n", A[n - 1], num);
    return 0;
}
