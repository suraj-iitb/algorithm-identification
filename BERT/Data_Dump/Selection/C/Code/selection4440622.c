#include<stdio.h>
int main(void){
    int N, i, j, tunc;
    int a[101];
    int min, count = 0, place=0;
    scanf("%d", &N);
    for (i = 0; i < N;i++){
        scanf("%d", &a[i]);
    }
    for (i = 0; i < N;i++){
        min = 101;
        for (j = i; j < N; j++){
            if(a[j] < min){
                min = a[j];
                place = j;
            }
            }
            if (min != a[i]){
                count++;
                tunc = a[i];
                a[i] = a[place];
                a[place] = tunc;
            }
    }
    printf("%d", a[0]);
    for (i = 1; i < N; i++){
        printf(" %d", a[i]);
    }
    printf("\n");
    printf("%d\n", count);
}
