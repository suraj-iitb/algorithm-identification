#include<stdio.h>
int main(void){
    int N;
    int a[100];
    scanf("%d", &N);
    int i, j, tunc, counter = 0;
    for (i = 0; i < N;i++){
        scanf("%d", &a[i]);
    }
    for (i = N - 1; i != 0;i--){
        for (j = N - 1; j != N - i - 1;j--)
            if (a[j - 1] > a[j])
            {
                //printf("%d %d\n", a[j - 1], a[j]);
                tunc = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tunc;
                counter++;
            }
    }
    for (i = 0; i < N-1;i++){
        printf("%d ", a[i]);
    }
    printf("%d\n", a[N - 1]);
    printf("%d\n", counter);
    return 0;
}
