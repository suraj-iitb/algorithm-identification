#include<stdio.h>
#define N 100
int main()
{
    int a,i,j,tmp;
    int cnt = 0;
    int A[N];

    scanf("%d",&a);
    for(i = 0 ; i < a ; i++){
        scanf("%d",&A[i]);
    }
    for(i = 0 ; i < a - 1 ; i++){
        for(j = a - 1 ; j >=i+1 ; j--){
            if(A[j] < A[j-1]){
                tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                cnt++;
        }
    }
}
    for(i = 0 ; i < a ; i++){
        printf("%d",A[i]);
        if(i < a - 1)printf(" ");
    }
    printf("\n%d\n",cnt);
    return 0;
}


