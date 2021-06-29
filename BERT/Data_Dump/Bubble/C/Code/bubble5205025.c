#include <stdio.h>
int main()
{
    int n;
    int A[101];
    int j = 0, counter = 0, i, temp;
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &A[i]);
    while(j < n){
        for(i = n - 1; i > j; i--){
            if(A[i - 1] > A[i]){
                temp = A[i - 1];
                A[i - 1] = A[i];
                A[i] = temp;
                counter++;
            }
        }
        j++;
    }
    for(i = 0; i < n; i++)
    {
        if(i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n%d\n", counter);
    return 0;
}
