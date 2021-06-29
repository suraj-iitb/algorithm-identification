#include<stdio.h>
int N;
void hprintf(int a[]){
    int i;
    for (i = 0; i < N; i++){
        if (i != N - 1){
            printf("%d ", a[i]);
        }
        else{
            printf("%d\n", a[i]);
        }
    }
    
}
int main(void){
    scanf("%d", &N);
    int a[N];
    int i, j;
    int tunc;
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    hprintf(a);
    for (i = 1; i < N; i++)
    {
        for (j = 0; j < i; j++){
            if(a[i] < a[j]){
                tunc = a[i];
                a[i] = a[j];
                a[j] = tunc;
            }
        }
        hprintf(a);
    }

    return 0;
}
