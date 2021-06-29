#include<stdio.h>
#define N 100
int main()
{
    int a,i,j,tmp,minj,cnt = 0;
    int A[N];

    scanf("%d",&a);
    for(i = 0 ; i < a ; i++){
        scanf("%d",&A[i]);
    }

    for(i = 0 ; i < a - 1 ; i++){
        minj = i;
        for(j = i+1 ; j < a ; j++){
            if(A[j] < A[minj])
            minj = j;
        }
        if(i != minj){
        tmp = A[i];
        A[i] = A[minj];
        A[minj] = tmp;
        cnt++;
        }
    }

    for(i = 0 ; i < a ; i++){
        printf("%d",A[i]);
        if(i < a - 1)printf(" ");
    }
    printf("\n%d\n",cnt);
    return 0;
}

