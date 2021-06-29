#include<stdio.h>
#define N 100
int main()
{
    int a,i,j,tmp;
    int flag = 0;
    int A[N];

    scanf("%d",&a);
    for(i = 0 ; i < a ; i++){
        scanf("%d",&A[i]);
    }
    for(i = 0 ; i < a ; i++){
        for(j = a - 1 ; j > i ; j--){
            if(A[j] < A[j-1]){
                tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                flag++;
        }
    }
}
    for(i = 0 ; i < a ; i++){
        printf("%d",A[i]);
        if(i < a - 1)printf(" ");
    }
    printf("\n%d\n",flag);
    return 0;
}
