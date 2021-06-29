#include<stdio.h>
#define N 100
int main(){
    
    int a,b,f,i,j,A[N],min=0,cnt = 0;

    scanf("%d",&a);
    for(i = 0;i < a;i++){
        scanf("%d",&A[i]);
    }

    for(i = 0;i < a;i++){
        f = 0;
        min = i;
        for(j = i;j < a;j++){
            if(A[j] < A[min]){
                f = 1;
                min = j;
            }
        }
        if(f == 1)cnt++;
            b = A[i];
            A[i] = A[min];
            A[min] = b;
        printf("%d",A[i]);
        if(i != a-1) printf(" ");
    }
    printf("\n");
    printf("%d\n",cnt);
    return 0;
}
