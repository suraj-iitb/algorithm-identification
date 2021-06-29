#include <stdio.h>

int main(){
    int N, A[100], i, j, minj, cou=0, sw, ch=0;
    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
    for(i=0; i<N; i++){
        minj=i;
        for(j=i; j<N; j++){
            if(A[j]<A[minj]){
                minj=j;
                ch=1;
            }
        }
        sw=A[i];
        A[i]=A[minj];
        A[minj]=sw;
        if(ch==1){
            cou++;
        }
        ch=0;
    }
    for(i=0; i<N-1; i++){
        printf("%d ", A[i]);
    }
    printf("%d\n%d\n", A[N-1], cou);
    return 0;
}
