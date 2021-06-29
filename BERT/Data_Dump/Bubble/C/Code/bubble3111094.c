#include <stdio.h>
int main()
{
  int n, A[100];
  int i, j,c;
  int cnt=0;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    for(i = 0; i < n; i++){
        for(j = (n - 1); j >= (i + 1); j--){
            if(A[j] < A[j - 1]){
                c = A[j];
                A[j] = A[j - 1];
                A[j - 1] = c;
                cnt++;
            }
        }
    }
    for(i = 0; i < n; i++){
        if(i == (n - 1)){
            printf("%d\n", A[i]);
        } else {
            printf("%d ", A[i]);
        }
    }
    printf("%d\n", cnt);
    return 0;
}
