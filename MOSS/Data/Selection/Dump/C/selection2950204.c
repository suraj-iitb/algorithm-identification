#include <stdio.h>
int main(){
    int N, a[101] = {0};
    int i, j, count = 0;
    int min,temp;
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d", &a[i]);
    }
    for(i = 0; i< N; i++){
        min = i;
        for(j = i; j < N; j++){
            if(a[j] < a[min]){
                min = j;
            } }
        if(a[i] > a[min]){
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
            count++;
        } }
    for(i = 0; i < N; i++){
        printf("%d", a[i]);
        if(i != N-1){printf(" ");
        } }
    printf("\n%d\n", count);
    return 0; }
