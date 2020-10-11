#include<stdio.h>
#include<stdlib.h>
#define N 2000001
#define V 10000

int main()
{
    int a,n,i,j,cnt = 0;
    int A[V],B[V];

    scanf("%d",&n);
    if(n < 1 || n > N)exit(1);

    for(i = 0 ; i < V ; i++){
        A[i] = 0;
    }
    for(i = 0 ; i < n ; i++){
        scanf("%d",&a);
        A[a]++;
    }
    for(i = 0 ; i < V ; i++){
        for(j = 0 ; j < A[i] ; j++){
            printf("%d",i);
            if(cnt < n-1){
                printf(" ");
                cnt++;
            }
        }
    }
    printf("\n");
    return 0;
}

