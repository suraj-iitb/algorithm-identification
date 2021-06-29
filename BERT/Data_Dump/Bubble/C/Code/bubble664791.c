#include <stdio.h>

int main(void){
    int N,tmp;
    int cnt = 0;
    int i,j;

    scanf("%d" ,&N);
    int num[N];

    for(i = 0;i < N;i++){
        scanf("%d", &num[i]);
    }

    for(i = 0; i < N;i++){
        for(j = N - 1;j > i;j--){
            if(num[j] < num[j-1]){
                tmp = num[j-1];
                num[j-1] = num[j];
                num[j] = tmp;
                cnt++;
            }
        }
    }

    for(i = 0; i < N - 1;i++){
        printf("%d ", num[i]);
    }
    printf("%d\n%d\n", num[N-1], cnt);

    return 0;
}
